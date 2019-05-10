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

/* 
 * File:   main.c
 * Author: erik
 *
 * Created on 9 de mayo de 2019, 13:09
 */

#include <stdio.h>
#include <stdlib.h>

#include "mango_server.h"

void print_endpoints(mango_server* server);

int main(int argc, char** argv) {    
    printf("[mango] - START\n");

    if(0) {
        printf("[mango][test1] adding endpoints\n");
        
        mango_server s = mango_server_create();
        
        mango_endpoint ep1 = {.address = "127.0.0.1", .port = 1337};
        mango_endpoint ep2 = {.address = "127.0.0.1", .port = 1338};
        
        bool ep1_added = mango_add_endpoint(&s, &ep1);
        printf("[mango]\t[test1] add ep1 - %s (total: %d)\n", (ep1_added ? "OK" : "ERROR"), s.endpoint_count);
        
        bool ep2_added = mango_add_endpoint(&s, &ep2);
        printf("[mango]\t[test1] add ep2 - %s (total: %d)\n", (ep2_added ? "OK" : "ERROR"), s.endpoint_count);
        
        bool ep1_added_again = mango_add_endpoint(&s, &ep1);
        printf("[mango]\t[test1] add ep1 again - %s (total: %d)\n", (!ep1_added_again ? "OK" : "ERROR"), s.endpoint_count);
        
        bool ep2_added_again = mango_add_endpoint(&s, &ep2);
        printf("[mango]\t[test1] add ep2 again - %s (total: %d)\n", (!ep2_added_again ? "OK" : "ERROR"), s.endpoint_count);
    
        print_endpoints(&s);
    }
    
    if(0) {
        printf("[mango][test2] removing endpoints\n");
        
        mango_server s = mango_server_create();
        
        mango_endpoint ep1 = {.address = "127.0.0.1", .port = 1337};
        mango_endpoint ep2 = {.address = "127.0.0.1", .port = 1338};
        mango_endpoint ep3 = {.address = "127.0.0.2", .port = 1339};
        
        mango_add_endpoint(&s, &ep1);
        mango_add_endpoint(&s, &ep2);
        mango_add_endpoint(&s, &ep3);
        
        print_endpoints(&s);
        printf("[mango]\t[test2] ep2 exists before remove? %s\n", (mango_endpoint_exists(&s, &ep2) ? "YES" : "NO"));
        mango_remove_endpoint(&s, &ep2);        
        printf("[mango]\t[test2] ep2 exists after remove? %s\n", (mango_endpoint_exists(&s, &ep2) ? "YES" : "NO"));
        
        print_endpoints(&s);
    }
    
    if(0) {
        printf("[mango][test3] removing all endpoints\n");
        
        mango_server s = mango_server_create();
        
        mango_endpoint ep1 = {.address = "127.0.0.1", .port = 1337};
        mango_endpoint ep2 = {.address = "127.0.0.1", .port = 1338};
        mango_endpoint ep3 = {.address = "127.0.0.2", .port = 1339};
        
        mango_add_endpoint(&s, &ep1);
        mango_add_endpoint(&s, &ep2);
        mango_add_endpoint(&s, &ep3);
        
        print_endpoints(&s);        
        mango_remove_all_endpoints(&s);                
        print_endpoints(&s);
    }
    
    if(1) {
        printf("[mango][test4] removing endpoints by\n");
        
        mango_server s = mango_server_create();
        
        mango_endpoint ep1 = {.address = "127.0.0.1", .port = 1337};
        mango_endpoint ep2 = {.address = "127.0.0.1", .port = 1338};
        mango_endpoint ep3 = {.address = "127.0.0.2", .port = 1339};
        
        mango_add_endpoint(&s, &ep1);
        mango_add_endpoint(&s, &ep2);
        mango_add_endpoint(&s, &ep3);
        
        print_endpoints(&s);        
        printf("[mango]\t[test4] removing endpoints with address '127.0.0.1'\n");
        mango_remove_endpoints_by_address(&s, "127.0.0.1");                
        print_endpoints(&s);
        
        printf("[mango]\t[test4] removing endpoints with port '1339'\n");
        mango_remove_endpoints_by_port(&s, 1339); 
        print_endpoints(&s);
    }
    
    printf("[mango] - END\n");

    return (EXIT_SUCCESS);
}

void print_endpoints(mango_server* server) {    
    uint8_t count = 0;
    mango_endpoint* current_endpoint = server->endpoints;
    
    printf("[print_endpoints] total endpoints: %d\n", server->endpoint_count);
    while(current_endpoint != NULL) {
        printf("\t#%d - %s:%d\n", count + 1, current_endpoint->address, current_endpoint->port);
        
        current_endpoint = current_endpoint->next_endpoint;
        count++;
    }
}