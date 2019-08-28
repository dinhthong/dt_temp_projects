#!/usr/bin/python

import webbrowser
import zipfile
from bs4 import BeautifulSoup
import urllib2
import lxml.html
from StringIO import StringIO
from zipfile import ZipFile
from urllib import urlopen
import requests ,io


def  directwithout(searchurl):
	linklist = []
	head = {'User-Agent': 'Mozilla/5.0'}
	req1 = urllib2.Request(searchurl,headers=head)
	MyFile1 = urllib2.urlopen(req1)
	MyHtml1 = MyFile1.read()
	MyFile1.close()
	soup1 = BeautifulSoup(MyHtml1,"lxml")
	i = 0
	for link in soup1.findAll('a'):

		if 'english' in link.get('href'):

		 	
		 	linklist.append(link.get('href'))

		 	

		 	if i < 5:
		 		
		 	 print "\n", i+1,':' ,link.findAll("span")[1].text.strip()
		 	 i = i+1
	print "\nCan't find the movie subtitle ? Make sure you enter the correct movie name"

	num = input("\nEnter the respective Number to Download: ")




	if num == 1:
	 f = 'https://subscene.com/'+linklist[0]
	 finalpage(f)

	if num == 2:
	 q = 'https://subscene.com/'+linklist[1]
	 finalpage(q)

	if num == 3:
	 w = 'https://subscene.com/'+linklist[2]
	 finalpage(w)

	if num == 4:
	 e = 'https://subscene.com/'+linklist[3]
	 finalpage(e)

	if num == 5:
	 r = 'https://subscene.com/'+linklist[4]
	 finalpage(r)

def finalpage(lastlink):
	r = {'User-Agent': 'Mozilla/5.0'}
	req2 = urllib2.Request(lastlink,headers=r)
	MyFile2 = urllib2.urlopen(req2)
	MyHtml2 = MyFile2.read()
	MyFile2.close()
	inside2 = BeautifulSoup(MyHtml2,"lxml").find("div", {"class": "download"}).find('a')
	download = 'https://subscene.com/'+inside2['href']
	print "Downloading and Extracting Subtitle"
	z = zipfile.ZipFile(io.BytesIO(requests.get(download).content)).extractall()
	print "Subtitle has downloaded Succesfully!!"


mna = raw_input("Enter Movie name: ")
mname = mna.replace(" ",'+').rstrip("+")
searchurl = "https://subscene.com/subtitles/title?q=" +mname+ ".720p"
#https://subscene.com/subtitles/title?q=Saving+Private+Ryan+1998&l=
print "\nGenerating Url"
hdr = {'User-Agent': 'Mozilla/5.0'}
req = urllib2.Request(searchurl,headers=hdr) #request url
MyFile = urllib2.urlopen(req)
MyHtml = MyFile.read()
MyFile.close()
soup = BeautifulSoup(MyHtml,"lxml")
a = soup.findAll()
j = len(a)
directwithout(searchurl)