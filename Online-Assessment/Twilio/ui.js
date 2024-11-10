/*
The component must have the following functionalities.
• The input should initially be empty. The user can type a date in this input box, for which the stock data must be searched. The date format must be d-mmmm-yyyy (e.g., 5-January-2000).
• Clicking on the 'Search' button should make an API GET call to URL
'https://jsonmock.hackerrank.com/api/st
ocks?date=(input}' using the JavaScript fetch API, specif©ally the fetch function. Here, (input) is the date entered into the text box. For example, for date 5-January-2000, the API hit is https://jsonmock.hackerrank.com/api/
stocks?date=5-January-2000. The date



The response will contain a data field
that contains stock data.
"data": [
"date": "5-January-
2000",
"open": 5265.09,
"high": 5464.35,
* "low": 5184.48,
"close": 5357
｝
App.js
X
challenge › src ›
6
7
8
9
10
11
12
13
14
15
16
17
18
const
ti
function
return
<div>
<h&
<St </div
;
}
export de
The data field is an array that contains a single object. Retrieve the open, close, high, and low values from this, and render it in the format explained.
• Display the data inside ‹ul data-


Display the data inside ‹ul data-testid="stock-data"></ul>. This list will have these list elements in this order.
• <i> Open: (open)</i>, where (open} is the open value from data above
o <li> Close: {close)</i>
, where {close) is the close value o <li>High: {high}</li>
, where (high} is the high value
• <> Low: (low<>, where flows is the low value
• The element <ul data-testid="stock-data"></ul» is re@dered only when data is fetched and the result is shown.
Initially, it is not rendered since no API has been hit yet.
• If the API returns no stock data, the app should render <div data-testid= "no-result">No Results Found</div> instead



If the API returns no stock data, the app should render <div data-testid="no-result">No Results Found</div> instead of the <ul> element. This element should be visible only when the data field is an empty array. This div should not be rendered initially because no API has been hit yet.
• Note that the input field accepts the date as text. Input will be tested only with valid dates, so writing input validation is not required.
The folkwving data-testid attributes are required Web IDE mponent for the tests to
pass:
A 0
Test Results
• Input should have the data-testid attribute 'app-input'.
Search button should have the data-


Search button should have the data-testid attribute 'submit-button'.
• <ul> should have the data-testid attribute 'stock-data'.
• The 'No Results Found' div should have the data-testid attribute 'no-result'.
Note that components have data-testid attributes for test cases and certain classes and ids for rendering purposes. These should not be changed.


import import
3
import
4
App.js
Keact
Trom
'react';
•/App. css';
'h8k-components';
import StockData from ' /components/stock-data/index.js';
5
6
const title = "Stock Data";
7
8
function App () {
9
10
11
12
13
14
15
16
17
18
export default App;

*/

import React, { useState } from 'react';

const title = "Stock Data";

function App() {
  const [inputDate, setInputDate] = useState(''); // State for the date input
  const [stockData, setStockData] = useState(null); // State for storing stock data
  const [noResult, setNoResult] = useState(false); // State for managing "No Results" display

  // Function to fetch stock data based on input date
  const fetchStockData = async () => {
    const url = `https://jsonmock.hackerrank.com/api/stocks?date=${inputDate}`;
    try {
      const response = await fetch(url);
      const data = await response.json();
      // Check if stock data is available
      if (data.data && data.data.length > 0) {
        setStockData(data.data[0]); // Set the stock data
        setNoResult(false); // Reset "No Results" state
      } else {
        setStockData(null); // Reset stock data if no result
        setNoResult(true); // Show "No Results" message
      }
    } catch (error) {
      console.error("Error fetching stock data:", error);
      setStockData(null); // Reset stock data in case of error
      setNoResult(true); // Show "No Results" message
    }
  };

  return (
    <div>
      <h1>{title}</h1>
      <input
        type="text"
        data-testid="app-input"
        value={inputDate}
        onChange={(e) => setInputDate(e.target.value)}
        placeholder="Enter date (e.g., 5-January-2000)"
      />
      <button data-testid="submit-button" onClick={fetchStockData}>
        Search
      </button>

      {/* Conditional rendering for stock data */}
      {stockData ? (
        <ul data-testid="stock-data">
          <li>Open: {stockData.open}</li>
          <li>Close: {stockData.close}</li>
          <li>High: {stockData.high}</li>
          <li>Low: {stockData.low}</li>
        </ul>
      ) : (
        noResult && <div data-testid="no-result">No Results Found</div>
      )}
    </div>
  );
}

export default App;
