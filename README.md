# image_processing_using_c++
## Problem Statement
The problem statement is to develop an algorithm or software that can convert a normal image to its mirror form and then to its grey scale form. The goal is to create an efficient and accurate system that can automatically process images, reflect them horizontally to create a mirror image, and then convert the resulting image to a grey scale format. This system should be able to handle a wide variety of image types and sizes and produce high-quality output that accurately reflects the original image. The system should also be user-friendly, with a simple interface that allows users to easily upload and process their images. Overall, the goal of this project is to provide a fast and reliable tool for converting images to their mirror and grey scale forms, which can be used in a wide range of applications such as image editing, computer vision, and graphic design.
### A normal image to the grey-scaled image
![image](https://github.com/ityashag/image_processing_using_c-/assets/97851640/42742ac0-17d6-4a68-81a8-fe3d5a1573b9)
### A flipped image to its greyscale form</br>
![image](https://github.com/ityashag/image_processing_using_c-/assets/97851640/60168c01-7c85-4221-b0d9-e742f08913c4)


</br>The goal is to solve the problem in the least complexity and retain the best quality of original picture.
# How to achieve this?
1. Load the image: The first step is to load the image you want to convert using an image processing library in your preferred programming language.
</br>2.Convert to mirror image: To create the mirror image, you need to reflect the pixels of the original image horizontally. One way to do this is to iterate over each row of pixels in the image and swap the pixels on the left side of the image with those on the right side. This can be achieved using a nested loop or a built-in function depending on the library you're using.
</br>3.Convert to grey scale: To convert the mirror image to grey scale, you need to remove the colour information from the image and only retain the brightness values. This can be done by iterating over each pixel in the image and taking the average of the red, green, and blue values to obtain a single value representing the brightness of the pixel. The resulting image will be a grey scale version of the mirror image.
</br>4.Save the image: Finally, you can save the resulting image in a file format of your choice using the image processing library you're working with.</br>
### To Flip an image or mirror it
 You need to reflect the pixels of the original image along a vertical axis. This means that the pixels on the left side of the image are moved to the right side, and the pixels on the right side of the image are moved to the left side. This will create a flipped version of the original image.</br>
To achieve this, you can use an image processing library in your preferred programming language that provides functions for manipulating images. One common library used for image processing is OpenCV, which has functions for flipping images. In OpenCV, you can use the cv2.flip() function to flip an image horizontally by passing the image array and the value 1 for the flip Code parameter.</br>
After flipping the image, you can save it to a file format of your choice, such as JPG. The resulting image will be a horizontally flipped version of the original RGB image.
It's important to note that the specific implementation may vary depending on the library and programming language you're using, and the method used to flip the image may differ slightly from library to library. However, the basic concept remains the same - reflecting the pixels of the original image along a vertical axis to create a flipped version of the image.

### To Grey Scale an RGB image
There are several methods you can grey scale an RGB image,
But first let’s define some useful terms,</br>
1.Color Models: Representing colours as numerical values is a necessary step in many applications. To do this, we use models that are mathematical models that describe ways of mapping colours to a set of numbers. Usually, a colour model defines three- or four-color components that are easily described through a coordinate system. Each colour that the model can represent corresponds to a point in this coordinate system.</br>
2. RGB: The most well-known colour model is RGB which stands for Red-Green-Blue. As the name suggests, this model represents colours using individual values for red, green, and blue. The RGB model is used in almost all digital screens throughout the world.</br>

Specifically, a colour is defined using three integer values from 0 to 255 for red, green, and blue, where a zero value means dark and a value of 255 means bright. Given the values, the final colour is defined when we mix these three basic colours weighted by their values.
![image](https://github.com/ityashag/image_processing_using_c-/assets/97851640/7b87cc34-8733-4ef4-8f68-e3116b959238)</br>
3.Grayscale: Grayscale is the simplest model since it defines colors using only one component that is lightness. The amount of lightness is described using a value ranging from 0 (black) to 255 (white). On the one hand, grayscale images convey less information than RGB. However, they are common in image processing because using a grayscale image requires less available space and is faster, especially when we deal with complex computations.</br>

#### Now to convert an RGB image to Greyscale, there are many methods like,</br>
•	Lightness method
A very simple method is to take the average value of the components with the highest and lowest value:
 ![image](https://github.com/ityashag/image_processing_using_c-/assets/97851640/0377e759-25bd-4608-8b29-ce0ff717159b)
</br>
We can easily see that this method presents a very serious weakness since one RGB component is not used.
</br>
•	Average method</br>
Another method is to take the average value of the three components (red, green, and blue) as the grayscale value:
 
 ![image](https://github.com/ityashag/image_processing_using_c-/assets/97851640/a18db2e8-ff54-4033-930e-f24f7f7d924e)
</br>
•	Luminosity method

We will be using Luminosity Method, that successfully solves the problems of previous methods. Based on the aforementioned observations, we should take a weighted average of the components. The contribution of blue to the final value should decrease, and the contribution of green should increase. After some experiments and more in-depth analysis, researchers have concluded in the equation:</br>Grayscale = 0.3 * R + 0.59 * G + 0.11 * B .
For a stock image, </br>
![image](https://github.com/ityashag/image_processing_using_c-/assets/97851640/9237fe7f-15ad-4f53-8df8-37f4ece9488d)

The best results can be seen in Luminosity method.

#  Performance Analysis

![image](https://github.com/ityashag/image_processing_using_c-/assets/97851640/aabac107-5e93-4ba2-816e-0b6ee301bfb9)</br>
Blue Line- >Time taken in Sequential.</br>Orange line->Time taken in Parallel.











