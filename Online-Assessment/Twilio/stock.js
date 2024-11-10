/*
You can query for the stock information using one of the following queries:
• https://jsonmock.hackerrank.com/api/st
ocks: This query returns all available stock information. The response is paginated, so you may need to
query https://jsonmock.hackerrank.com/a
pi/stocks./?page=pageNumber, where pageNumber is an integer that describes the page number to view (e.g., 1, 2, etc.).
• https://jsonmock.hackerrank.com/api/st
ocks/?key=value: This query returns all the results where the searched key exactly matches value. The response is paginated so you may need to
query https: //jsonmock.hackerrank.com/a
p1/ stocks/?key=value&page=pageNumber, where pageNumber is an integer that describes the page number you would like to view (e.g., 1, 2, etc.).
• https://jsonmock.hackerrank.com/api/st
ocks/search? key=value: This query returns all results where the searched key has values that contains value as a substring. The response is paginated so you may need to
query https://jsonmock.hackerrank.com/a
pi/stocks/search?
key=value&page=pageNumber, where pageNumber is an integer that describes the page number to view (e.g., 1, 2, etc.).


All the queries return a JSON response with the following five fields:
• page: The current page.
• per_page: The maximum number of results per page.
• total: The total number of records found.
• total_pages: The total number of pages which must be queried to get as the results.
• data: An array of JSON objects that contain the stock information. The JSON contains the following five fields, each of which can be used as the key to query:
• date: A string that describes the date on which the stock information is provided.
The date format is d-mmm-yyyy, where d describes a valid day of the month, mmm describes the complete name of the month (e.g., January, February, March, etc.), and yyyy describes the year. The date is in the range 5-January-2000 to 1-January-2014 inclusive. There may not be information for some of the dates, and the information is available for Monday
through Friday only.
• open: A float value that describes the stock's open price on the given date.
• close: A float value that describes the stock's close price on the given date.
• high: A float value that describes the stock's highest price on the given date.
• low: A float value that describes the stock's


Function Description
Complete the function openAndClosePrices in the editor below. It should print the available stock information for each stock within the given date range. The information printed should be three space separated values that describe the date, the open price, and the close price respectively.
The order of the dates in the output does not matter and there is no return value.
openAndClosePrices has the following parameters:
Language
1 › proc
12
13
14
15
16
17
/*
* Cr
* Be
* funct
18
19
20
21
22 › proce:
firstDate: a string that represents the first date to report
to report
lastDate: a string that represents the last date
• Input Format For Custom Testing
• Sample Case 0
Sample Input
1-January-2000
11-January-2000
*/


const fetch = require('node-fetch'); // Only required for Node.js environment

async function openAndClosePrices(firstDate, lastDate) {
    let page = 1;
    const stockData = [];

    // Helper function to fetch data from a specific page
    async function fetchData(page) {
        const url = `https://jsonmock.hackerrank.com/api/stocks?page=${page}`;
        const response = await fetch(url);
        const data = await response.json();
        return data;
    }

    // Loop through pages to collect stock data in the date range
    while (true) {
        const response = await fetchData(page);

        // If no more data or no records, break the loop
        if (!response || response.data.length === 0) break;

        // Filter data within the date range and add it to stockData
        response.data.forEach(stock => {
            const stockDate = stock.date;
            if (new Date(stockDate) >= new Date(firstDate) && new Date(stockDate) <= new Date(lastDate)) {
                stockData.push(`${stock.date} ${stock.open} ${stock.close}`);
            }
        });

        // If we've reached the last page, exit the loop
        if (page >= response.total_pages) break;

        page++;
    }

    // Print each stock entry within the date range
    stockData.forEach(data => console.log(data));
}

// Example usage
openAndClosePrices("1-January-2000", "11-January-2000");
