<h1 align="center">
  <br>
  <a href="https://github.com/TalMizrahii/AP1Project"><img src="https://img.icons8.com/color/344/c-plus-plus-logo.png" alt="C++" width="200"></a>
  <br>
  Advanced-Programming-1
  <br>
</h1>

<h4 align="center">This github repository is for the assignments given in Advanced Programming 1 course, Bar Ilan University.


<p align="center">
  <a href="#description">Description</a> •
  <a href="#implementation">Implementation</a> •
  <a href="#dependencies">Dependencies</a> •
  <a href="#installing-and-executing">Installing And Executing</a> •
  <a href="#authors">Authors</a> 
</p>

## Description

The task is to get two vectors from the user and to calculate different distances between them.

The Distances are:

* [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance)

![image](https://user-images.githubusercontent.com/103560553/202403137-049e516b-ac15-4e21-abbc-bf4f465a83bf.png)


* [Taxicab geometry](https://en.wikipedia.org/wiki/Taxicab_geometry)

![image](https://user-images.githubusercontent.com/103560553/202403477-4c2885df-8eee-4721-897b-dee4e95c4ed0.png)


* [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance)

![image](https://user-images.githubusercontent.com/103560553/202403736-3438755a-f128-46a9-8f55-4b1cf69a215f.png)


* [Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance)

![image](https://user-images.githubusercontent.com/103560553/202403909-432f6285-c7cb-4a78-b9e7-a0b6b837c455.png)


* [Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance)

![image](https://user-images.githubusercontent.com/103560553/202404050-595c6cba-1b98-42ba-868c-c2c28586d6e4.png)

## Implementation
The input to the program is received by the user from the keyboard. After that, the input is passed to a validation check, which accept:

* Only doubles or integers.
* Negative or positive numbers.
* The vectors must be equally sized.
* No special characters allowed.

For example, (0, -1.1, 2) and (1, 2, 3) is a valid input, but (a, 3, 4) and (1., .1, 5, 3) is not (not equally sized and contain illegal characters).

In the main.cpp file, we used the "iostream libary" to get the user input as a stream (string).
  Then we use several integrity checks to validate the string, if the string does not pass the integrity checks, we print an eror massage and close the program.
Assume we pass all the tests, then we "push" the valid string into double vector. 

Additionally, two out of the five distance function uses the Minkowski distance, because:
* taxicabDistance = minkowskiDistance(P = 1)
* euclideanDistance = minkowskiDistance(P = 2)

We used the minkowskiDistance to receive P=2.

The Distances class contains all calculations regard to the algorithms, in addition to the print function, which presents the result of each calculation according to the order specified above.

## Dependencies

* The program tested for linux machines.
* Compiled with g++.

## Installing And Executing

To clone and run this application, you'll need [Git](https://git-scm.com) installed on your computer. From your command line:

```bash
# Clone this repository.
$ git clone https://github.com/TalMizrahii/AP1Project

# Go into the repository.
$ cd AP1Project

# Compile using makefile.
$ make
```

```bash
# Run the program on Linux:
$ ./a.out
```

```bash
# Run the program on Windows:
$ a.out
```

```bash
# After running, clean all unnecessary files.
$ make clean
```

## Authors
* [@Yuval Arbel](https://github.com/YuvalArbel1)
* [@Tal Mizrahi](https://github.com/TalMizrahii)

