const socket = io();

socket.on('recieved', (data) => {
    let temp = ''
    data.msg.forEach(d => {
        temp += `${d}<br>`;
    });
    document.getElementById('logTxt').innerHTML = temp;
});
