#!/usr/bin/python

import MySQLdb
import sys

def insertRecord():
    return

def deleteRecord():
    return

def loadDataFile(db):
    # prepare a cursor object using cursor() method
    cursor = db.cursor()

    with open("t200.txt", 'r') as f:
        for line in f:
            line = line.split(' ')
            print line[0], line[1], line[2], line[3], line[4]
            print long(line[0])
            # Prepare SQL query to INSERT a record into the database.
            sql = "INSERT INTO Client(PHONE, LAST_NAME, FIRST_NAME, TOWN, INVOICE) VALUES ('%ld', '%s', '%s', '%s', '%f')" % (long(line[0]), line[1], line[2], line[3], float(line[4])) 
            try:
                # Execute the SQL command
                cursor.execute(sql)
                # Commit your changes in the database
                db.commit()
            except:
                print sys.exc_info()[0]
                raise

if __name__ == "__main__":
    # Open database connection
    db = MySQLdb.connect("localhost","root","metallica","K22_PROJECT1" )

    
    loadDataFile(db)
