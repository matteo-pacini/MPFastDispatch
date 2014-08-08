#MPFastDispatch

MPFastDispatch is a collection of helper macros for GCD.

#Integration

Add this into your Podfile:

    pod 'MPFastDispatch', '~> 0.1.0'

Import the class in your prefix:

    #import <MPFastDispatch.h>

#Macros (so far)

    @once(BLOCK) //"dispatch_once" shorthand
    @after(SECONDS,BLOCK)  //"dispatch_after" shorthand
    @main(BLOCK)  //Executes a block on the main queue

#Comparison

##Dispatch a block asynchronously on the main queue

To dispatch a block on the main queue, you would do...

    dispatch_async(dispatch_get_main_queue(), ^{
        CODE
    });

With **MPFastDispatch** you can do:

    @main(^{
        CODE
    })

##Dispatch a block once

To dispatch a block once you would do...

    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CODE
    });

With **MPFastDispatch** you can do:

    @once(^{
        CODE
    })


##Dispatch a block after n seconds

To dispatch a block once you would do...

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(SECONDS * NSEC_PER_SEC)), 
        dispatch_get_main_queue(), 
        ^{
            CODE
         });

With **MPFastDispatch** you can do:

    @after(SECONDS,^{
        CODE
    })

#Swift

Swift won't be supported as it doesn't include a preprocessor.

#To Do / Contribute

TBW

Fork the repo and send a pull request!

#License

    Copyright (c) 2014 Matteo Pacini
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

