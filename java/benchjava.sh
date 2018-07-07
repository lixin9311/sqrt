#!/bin/bash
javac Sqrt.java
java Sqrt 2> bench-java.log
for i in {2..100}
do
   java Sqrt 2>> bench-java.log
done