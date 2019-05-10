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

/*
 * 
 */
int main(int argc, char** argv) {    
    printf("[mango] - START\n");

    if(1) {
        printf("[mango][test1] adding endpoints\n");
        
        mango_server s = mango_server_create();
        
        mango_endpoint ep1 = {.address = "127.0.0.1", .port = 1337};
        mango_endpoint ep2 = {.address = "127.0.0.1", .port = 1338};
        
        bool ep1_added = mango_add_endpoint(&s, ep1);
        printf("[mango]\t[test1] add ep1 - %s (total: %d)\n", (ep1_added ? "OK" : "ERROR"), s.endpoint_count);
        
        bool ep2_added = mango_add_endpoint(&s, ep2);
        printf("[mango]\t[test1] add ep2 - %s (total: %d)\n", (ep2_added ? "OK" : "ERROR"), s.endpoint_count);
        
        bool ep1_added_again = mango_add_endpoint(&s, ep1);
        printf("[mango]\t[test1] add ep1 again - %s (total: %d)\n", (!ep1_added_again ? "OK" : "ERROR"), s.endpoint_count);
        
        bool ep2_added_again = mango_add_endpoint(&s, ep2);
        printf("[mango]\t[test1] add ep2 again - %s (total: %d)\n", (!ep2_added_again ? "OK" : "ERROR"), s.endpoint_count);
    
    }
    
    printf("[mango] - END\n");

    return (EXIT_SUCCESS);
}

