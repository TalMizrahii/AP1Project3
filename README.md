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

*The final project seats in the "main" branch!*

In this program, we asked to calculate the [KNN](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm) (K nearest neighbors) to a given vector.

The program receives 3 arguments:
* 1. The number K for the KNN algorithm.
* 2. The path to the database (explained later).
* 3. The distance calculation was wanted to be used in the KNN algorithm.
  
The third argument (The distance calculation) is interpreted as:
  * MUN - [Taxicab geometry](https://en.wikipedia.org/wiki/Taxicab_geometry)
  * AUC - [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance)
  * CHB - [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance)
  * CAN - [Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance)
  * MIN - [Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance)
  
  
 We use a given database named "datasets", containing .cvs files. each row in a file represents a vector of doubles. The last cell in the row represents the classification of the vector. 

We created a RelativeVector class, which contains the vector of doubles and the classification for each row. We calculated the KNN using a hash map and returned the resulting classification.

At the beginning of the program, the user needs to enter a vector that he wants to classify. This vector has a format, and if the user doesn't follow it the program will print "Illegal format" and will shut down the program. If the program won't find the .csv file, it will print "NO FILE" and will also shut down. 



## Implementation
  
  The code is divided to two main attributes - Distances and ControlAndData.
  
  ### ControlAndData
  The control and data directory contain the FileReader class, responsible to extract the data from the database to a vector of RelativeVector members. It uses the Validation class to make sure that all data extracted is valid and no errors occur during the extraction. It also contains the Knnalgorithm class to calculate the result using hash map for better preformance.
  
  ### Distances
  The distances class is composed of the 5 distance calculations mentioned above. All of those classes inherit from the AbstractDistance class, containing the "calculateDistance" method. The reason for that is to make the code compatible for change of the metric during run time.

## Dependencies

* The program tested for linux machines.
* Compiled with g++.

## Installing And Executing

To clone and run this application, you'll need [Git](https://git-scm.com) installed on your computer. From your command line:

```bash
# Clone this repository.
$ git clone https://github.com/TalMizrahii/AP1Project2

# Go into the repository.
$ cd AP1Project2

# Compile using makefile.
$ make
```
  you can choose which data file to run:
  
```bash
# Run iris
$ make run-iris
```
```bash
# Run wine
$ make run-wine
```
  ```bash
# Run beans
$ make run-beans
```
  To clean the .exe/out file:
  ```bash
# clean
$ make clean
```

## Authors
* [@Yuval Arbel](https://github.com/YuvalArbel1)
* [@Tal Mizrahi](https://github.com/TalMizrahii)

