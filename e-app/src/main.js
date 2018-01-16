// electron base objects
const electron = require("electron");
//electron app object is the main application
const app = electron.app;
// BrowserWindow is a class which is used in the closure the following statement is not a necessity
const BrowserWindow = electron.BrowserWindow;
const path  = require('path');
const url   = require('url');

// mainWindow is a global shared across events as a closure
let mainWindow = null;


app.on('ready' , function(){
	console.log("App is ready! Creating a window now");
	mainWindow = new BrowserWindow({height:600,
        width:800,
      //  webPreferences:{webSecurity:false,
        //    allowRunningInsecureContent:true}
	});
	// following fails it used to work with old electron tuts
	//mainWindow.loadURL("file://" + __dirname + "/src/index.html");
    var resUrl = url.format({
		"pathname":path.join(__dirname, "/index.html"),
		"protocol":"file",
		"slashes":true});
    console.log('loading ' + resUrl);
	mainWindow.loadURL(resUrl);
	
	mainWindow.on("closed", function() {
		console.log("MainWindow is now closing closing the application");
		process.exit();
	});
});

function counter(counterBegin){
    if (!counterBegin){
        counterBegin = 20;
    }
    count = counterBegin;
    let timer = setInterval(function () {

        mainWindow.webContents.send('countdown', count);
        console.log(count);
        count--;
        if (count < 0){
            clearInterval(timer);
        }
    }, 1000);
}

electron.ipcMain.on('counter-start', function (event, counterBegin) {
    counter(counterBegin);
});


