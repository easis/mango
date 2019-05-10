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
 * File:   mango_server.h
 * Author: erik
 *
 * Created on 9 de mayo de 2019, 13:12
 */

#ifndef MANGO_SERVER_H
#define MANGO_SERVER_H

#include "mango.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct mango_endpoint_t {
        char* address;
        uint32_t port;
        
        void* next_endpoint;
    } mango_endpoint;

    typedef struct mango_server_t {
        mango_endpoint* endpoints;
        uint8_t endpoint_count;
    } mango_server;
    
    mango_server mango_server_create();
    
    bool mango_add_endpoint(mango_server* server, mango_endpoint endpoint);
    bool mango_add_endpoint_by_address(mango_server* server, char* address, uint32_t port);
    bool mango_endpoint_exists(mango_server* server, mango_endpoint endpoint);



#ifdef __cplusplus
}
#endif

#endif /* MANGO_SERVER_H */

