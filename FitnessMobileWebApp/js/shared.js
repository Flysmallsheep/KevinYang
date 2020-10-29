// Shared code needed by all three pages.

// Kimtesting

// Prefix to use for Local Storage.  You may change this.
var APP_PREFIX = "monash.mcd4290.runChallengeApp";


//!!!!!!!!!!!!!!!!!!--------Global Variables---------//!!!!!!!!!!!!!!!!!!

//updatedLocation:
let oldLocation;
//currentLocation:
let currentLng;
let currentLat;
let currentLocation;
//startLocation:
let startLng;
let startLat;
let startLocation;
//destinationLocation:
let destinationLng;
let destinationLat;
let destinationLocation;
//distance between start and destination:
let distance;














//The Run Class begins here:
class Run{
	
	//constructor:
	constructor(startLocation, destinationLocation, currentLocation, Tdistance, arraryOfLocations, timeStarted, timeCompleted, savedtime){
		this._Runlist=[];
        this._startLocation = startLocation; 			//This should be a lnglat obj, example: [145.48332,-35.68439]
		this._destinationLocation = destinationLocation;
		this._currentLocation = currentLocation;
		this._arraryOfLocations = arraryOfLocations;	//nested array, example: [[145.48332,-35.68439],[167.48332,-39.68439]]
        this._Tdistance = Tdistance;
		this._timeStarted = timeStarted;
		this._timeCompleted = timeCompleted;
        this._totalDistance = 0;
        this._timechecked = savedtime;
	}
	
	//public methods (To be continued... Have to add more thing on it that depend on the tasks):
	title(){
		let titleMsg = "Hello, let's begin the new run!";
		return titleMsg;
	}
	
    
    accuDistance(dist){
        // accmulate distance
        this.totalDistance += dist;
    }
	
	endCurrentRun(){
		//Calculate time token
        this._timeCompleted = new Data();
        let diff = this._timeCompleted - this._timeStarted;
        let hrs = diff/3600000; diff % 3600000;
        let min = diff/60000; diff % 60000;
        let sec = diff/1000;
        this._time = hrs.toFixed(2) + "H " + min.toFixed(2) + "M " + sec.toFixed(2) + "S ";
        savedRuns.push(this);
	}
    
    storeCurrentRun(list){
        localStorage.setItem(APP_PREFIX, JSON.stringify(list));//save the new run in the local storage 
    }
	
    
	
	set_timechecked(tc){
        this._timechecked=tc;
    }	
    
    get_timechecked() {
        return this._timechecked;
    }
    
	getCurrentLocation(){
		return this._currentLocation;
	}
	
	getStartLocation(){
		return this._startLocation;
		
	}
	
	getDestinationLocation(){
		return this._destinationLocation;
	}
	
	
	addnewRun(obj) { //From localStorage
    this._roomList.push(obj)
    }
	
	getTimeStarted(){
		return this._timeStarted;
	}
	
	getTimeCompleted(){
		return this._timeCompleted;
	}
    
    getTime(){
        return this._time;
    }
    
    getDistance(){
        return this._totalDistance;
    }
	
	getListOfRun(){
		return this._Runlist
	}
	
    resetlist(array){
        this._Runlist=array
    }
	repeatARun(){
		
	}
	
}
	//Functionality that has to be achieved: 
	//4.begin the run 5. complete the run 6.store the run 7.show the lists of run 8. view a run 9.repeat a run

	

