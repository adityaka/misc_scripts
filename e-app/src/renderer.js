'use strict';

function message(msg){
    console.log(msg);
}
const electron = require('electron')

// an experiment in loading of elements which used  to help in pre-historic ages of the browser wars
document.addEventListener('load', function () {
    message('document is now loaded')
}); // doesn't work for some reason neither gives an error which means the event is triggering before the binding
window.addEventListener('load', function () {
    message('window is now loaded');
}); //this works always very reliable
//document.getElementsByTagName('body')[0].addEventListener('load', function () {
//    message('body is now loaded');
//});
// doesn't work for some reason fails if the scrupt is placed in head we can include this in the document.onload

// renderrer ipc messages

document.getElementById('btnCounter').addEventListener('click', function () {
    console.log('start the count down');
    electron.ipcRenderer.send('counter-start', 20);
});

electron.ipcRenderer.on('countdown', function(event, count){
    document.getElementById('lblCount').innerHTML = count;
});


