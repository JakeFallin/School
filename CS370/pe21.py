#I pledge my honor that I have abided by the stevens Honor System
#Jake Fallin, Dylan DiGeronimo, Kexian Wu

import time 
import math

#setup variables
limit = 100000
nums = [1] * limit
sums = [0]
#compute time
start = time.time()

#print method for time
def printTimePrecision(time):
    print "Time: {:0.2f} ms".format(time)

#print method for each pair of amicable numbers
def printPairs(a, b):
    print "({},{})".format(a,b)

#print method for the sum of amicable numbers
def printSum(sums):
    #add up pairs into sum
    s = sum(i for i in sums)
    print "Sum: {} for Limit: 100000".format(s)

#this sums the proper divisors
def properDivisors(limit):  
    #starting at 2 (min possible number) 
    for i in range(2, limit):
        #check in this range to seive out proper divisors
        for j in range(i + 1, limit // i):
            #fill up the array 
            nums[i*j] += i+j

#look for amicable pairs
def amicableNumbers(limit, sums):
    for i in range(2, limit):
        #condition being that when d(d(a)) = a (nums[nums[i]] == i) and d(a) < i
        #this works as an extension the PE #21 condition of d(a)=b & d(b)=a when a!=b
        #but as an extension so it works up to limit = 100000
        if nums[nums[i]] == i and nums[i] < i:
            #add to amicable pairs for summing 
            sums += [nums[i], i]
            #print them
            printPairs(nums[i], i)

#call functions
properDivisors(limit)
amicableNumbers(limit, sums)

#end of runtume
end = time.time()

#print everything
printSum(sums)
printTimePrecision(end-start)




