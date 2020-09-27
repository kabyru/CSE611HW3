"""
CSE 611 HW4 Loop Order Testing Code
This program will analyze what elements are accessed when certain loop orders are used.
"""

import csv

n = 3

with open('IJKresults.csv', 'w', newline='') as csvfile:
    resultWriter = csv.writer(csvfile, delimiter=',', quotechar= "'", quoting=csv.QUOTE_MINIMAL)
    resultWriter.writerow(['i', 'j', 'k', 'A Location', 'B Location', 'C Location'])

    for i in range(0,n):
        for j in range(0,n):
            for k in range(0,n):
                A_loc = (i+k*n)
                B_loc = (k+j*n)
                C_loc = (i+j*n)

                resultWriter.writerow([str(i), str(j), str(k), str(A_loc), str(B_loc), str(C_loc)])

with open('IKJresults.csv', 'w', newline='') as csvfile:
    resultWriter = csv.writer(csvfile, delimiter=',', quotechar= "'", quoting=csv.QUOTE_MINIMAL)
    resultWriter.writerow(['i', 'j', 'k', 'A Location', 'B Location', 'C Location'])

    for i in range(0,n):
        for k in range(0,n):
            for j in range(0,n):
                A_loc = (i+k*n)
                B_loc = (k+j*n)
                C_loc = (i+j*n)

                resultWriter.writerow([str(i), str(j), str(k), str(A_loc), str(B_loc), str(C_loc)])

with open('JIKresults.csv', 'w', newline='') as csvfile:
    resultWriter = csv.writer(csvfile, delimiter=',', quotechar= "'", quoting=csv.QUOTE_MINIMAL)
    resultWriter.writerow(['i', 'j', 'k', 'A Location', 'B Location', 'C Location'])

    for j in range(0,n):
        for i in range(0,n):
            for k in range(0,n):
                A_loc = (i+k*n)
                B_loc = (k+j*n)
                C_loc = (i+j*n)

                resultWriter.writerow([str(i), str(j), str(k), str(A_loc), str(B_loc), str(C_loc)])

with open('JKIresults.csv', 'w', newline='') as csvfile:
    resultWriter = csv.writer(csvfile, delimiter=',', quotechar= "'", quoting=csv.QUOTE_MINIMAL)
    resultWriter.writerow(['i', 'j', 'k', 'A Location', 'B Location', 'C Location'])

    for j in range(0,n):
        for k in range(0,n):
            for i in range(0,n):
                A_loc = (i+k*n)
                B_loc = (k+j*n)
                C_loc = (i+j*n)

                resultWriter.writerow([str(i), str(j), str(k), str(A_loc), str(B_loc), str(C_loc)])

with open('KIJresults.csv', 'w', newline='') as csvfile:
    resultWriter = csv.writer(csvfile, delimiter=',', quotechar= "'", quoting=csv.QUOTE_MINIMAL)
    resultWriter.writerow(['i', 'j', 'k', 'A Location', 'B Location', 'C Location'])

    for k in range(0,n):
        for i in range(0,n):
            for j in range(0,n):
                A_loc = (i+k*n)
                B_loc = (k+j*n)
                C_loc = (i+j*n)

                resultWriter.writerow([str(i), str(j), str(k), str(A_loc), str(B_loc), str(C_loc)])

with open('KJIresults.csv', 'w', newline='') as csvfile:
    resultWriter = csv.writer(csvfile, delimiter=',', quotechar= "'", quoting=csv.QUOTE_MINIMAL)
    resultWriter.writerow(['i', 'j', 'k', 'A Location', 'B Location', 'C Location'])

    for k in range(0,n):
        for j in range(0,n):
            for i in range(0,n):
                A_loc = (i+k*n)
                B_loc = (k+j*n)
                C_loc = (i+j*n)

                resultWriter.writerow([str(i), str(j), str(k), str(A_loc), str(B_loc), str(C_loc)])