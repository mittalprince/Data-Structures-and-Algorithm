const express = require('express');
const socketio = require('socket.io');
const fs = require('fs');
const readline = require('readline');
const path = require('path');
const http = require('http');
const app = express();

const server = http.createServer(app);

const io = socketio(server);
app.use(express.static(path.join(__dirname, '/public')))

async function processLineByLine(logs) {
    const fileStream = fs.createReadStream('./log.txt');

    const rl = readline.createInterface({
        input: fileStream,
        crlfDelay: Infinity
    });
    for await (const line of rl) {
        logs.push(line);
        if (logs.length > 10) {
            logs.shift();
        }
    }
}

fs.watch('./log.txt', {}, async(eventType, filename) => {
    if (filename) {
        let logs = []
        await processLineByLine(logs);
        io.emit('recieved', {
            msg: logs,
        })
    }
});

server.listen(8000, () => {
    console.log('server has started at 8000')
})