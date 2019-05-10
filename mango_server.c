/*
 * The MIT License
 *
 * Copyright 2019 erik.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "mango_server.h"

mango_server mango_server_create() {
    mango_server server;

    server.endpoint_count = 0;
    server.endpoints = NULL;

    return server;
}

bool mango_add_endpoint(mango_server* server, mango_endpoint endpoint) {
    uint8_t current_endpoint_count = server->endpoint_count;
        
    if(mango_endpoint_exists(server, endpoint)) {
        return false;
    }

    if(server->endpoints == NULL) {
        server->endpoints = malloc (sizeof(mango_endpoint));
        *server->endpoints = endpoint;
        server->endpoints->next_endpoint = NULL;
    } else {
        mango_endpoint* current_endpoint = server->endpoints;
        while(current_endpoint->next_endpoint != NULL) {     
            current_endpoint = current_endpoint->next_endpoint;
        }
        
        current_endpoint->next_endpoint = malloc (sizeof(mango_endpoint));
        current_endpoint->next_endpoint = (void*) &endpoint;
        ((mango_endpoint*) current_endpoint->next_endpoint)->next_endpoint = NULL;
    }   
    
    server->endpoint_count = current_endpoint_count + 1;

    return true;
}

bool mango_add_endpoint_by_address(mango_server* server, char* address, uint32_t port) {
    mango_endpoint endpoint;

    endpoint.address = calloc(strlen(address) + 1, sizeof (char));
    strcpy(endpoint.address, address);

    endpoint.port = port;

    return (mango_add_endpoint(server, endpoint));
}

bool mango_endpoint_exists(mango_server* server, mango_endpoint endpoint) {
    if(server->endpoint_count <= 0) {
        return false;
    }
    
    if(server->endpoints == NULL) {
        return false;
    }
    
    mango_endpoint* current_endpoint = server->endpoints;
    while (current_endpoint != NULL) {
        if (current_endpoint->port == endpoint.port && (strcmp(endpoint.address, current_endpoint->address) == 0)) {
            return true;
        }

        current_endpoint = current_endpoint->next_endpoint;
    }

    return false;
}