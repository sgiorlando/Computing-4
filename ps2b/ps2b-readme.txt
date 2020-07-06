Name: Scott Giorlando

Functionality of Program: My program should be working fully as it's supposed to be.  It takes in 4 arguments, an input file an output file to be written to, a seed and the tap position.
My program takes in the image and successfully scrambles it when it comes to the output.  It also works when taking in the argument backwards, and it returns the original image that was given.

Other: For some odd reason when I was implementing my changeImage function, I kept getting segmentation faults when I was trying to run my program.  I followed the pixels.cpp that was given
on my professors website when it came to making the pixels change colors.  I ended up finding out that my program wouldn't work unless the variables used in the loops were unsigned ints instead
of regular ints which was a bit strange.  Also for some odd reason my input file window keeps appearing to be a white box and not the actual image that was given (attempted to remove the sf::Color::White inside the window.clear(), but it doesn't affect anything.),
but when I use the scrambled image as my input it seems to return the original input image back as the output.
