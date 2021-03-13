#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 10 21:30:08 2021

@author: michaek05130505gmail.com
"""

import csv
from datetime import datetime
import requests
from bs4 import BeautifulSoup
import numpy as np
from simplified_scrapy.simplified_doc import SimplifiedDoc

def get_url(position, location, page):
    template = 'https://tw.indeed.com/jobs?q={}&rbl={}&start={}0'
    url = template.format(position, location, page)
    return url

def get_record(card):
    atag = card.h2.a
    job_title = atag.get('title')
    job_url =  'https://tw.indeed.com' + atag.get('href')
    company = card.find('span', 'company').text.strip()
    job_location =  card.find('div', 'recJobLoc').get('data-rc-loc')
    job_summary = card.find('div', 'summary').text.strip()
    post_date = card.find('span', 'date').text
    today = datetime.today().strftime('%Y-%m-%d')
    try: 
        job_salary = card.find('span', 'salaryText').text.strip()
    except AttributeError:
        job_salary = ' '
    record = (job_title, company, job_location, post_date, today, job_summary, job_salary, job_url)
    
    return record

def main(position, location, page):
    records = []
    url = get_url(position, location, page)
    
    for i in range(3):
        try: 
            url = get_url("summer+intern", "台北市", i)
        
        except AttributeError:
            break
        
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        cards = soup.find_all('div', 'jobsearch-SerpJobCard')
    
        for card in cards:
            record = get_record(card)
            records.append(record)
    
    with open('results.csv', 'w', newline = '', encoding = 'utf-8') as f:
        writer = csv.writer(f)
        writer.writerow(['JobTitle', 'Company', 'Location', 'PostDate', 'ExtractDate', 'Summary', 'Salary', 'Job_url'])
        writer.writerows(records)



#run the main program
main('summer intern', '台北市', 0)