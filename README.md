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

In this program, we implemented a TCP server and client. The client sends to the server a message contains a vector, calculation function and a number K. The server calculate the KNN from a given database (explained later), and returns the classification of vector by this database.

### The Client

The client recievs two system arguments:
 * The IP address of the server.
 * The port number the server uses.
 
 Afetr that, the client asks the user to enter a vector (same sized as the vectors in the server's database), a metric calculation function and a number K for the KNN calculation. If the client enters "-1" he closes the socket.
 
 The client sends the message to the server and prints the reply.
 
### The Server

The server recievs two system arguments:
 * A path the a file database, contains classifeid vectors in a CSV file.
 * The port number to use (needs to be an unused port number).
 
We use a given database named "datasets", containing .cvs files. Each row in a file represents a vector of doubles. The last cell in the row represents the classification of the vector. 
  
The server sets it's socket to listen to 5 clients at most.

He processes the message from the client to 3 elements (by this order):

* 1. The vector - must be same size as the vectors in the database.
* 2. The distance calculation was wanted to be used in the KNN algorithm.
* 3. The number K for the KNN algorithm.

The second argument (The distance calculation) is interpreted as:
  * MUN - [Taxicab geometry](https://en.wikipedia.org/wiki/Taxicab_geometry)
  * AUC - [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance)
  * CHB - [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance)
  * CAN - [Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance)
  * MIN - [Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance)
  
The third argument, the KNN, must be a positive number. If the K is larger then the number of vectors in the file, the algorithm will calaulate the maximum vectors he can from the database.

The servre calculates the KNN and returns the classification to the client's socket. After that, the server waits to a new message from the client. If the client sends "-1", the server will close the client's socket and accept a new client. If the client sends any invalid message (not by format, invalid metric, etc), the server will reply "invalid message".


## Implementation
  
### client

The client uses the 

### Server

We created a RelativeVector class, which contains the vector of doubles and the classification for each row. We calculated the KNN using a hash map and returned the resulting classification.

At the beginning of the program, the user needs to enter a vector that he wants to classify. This vector has a format, and if the user doesn't follow it the program will print "Illegal format" and will shut down the program. If the program won't find the .csv file, it will print "NO FILE" and will also shut down. 

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

