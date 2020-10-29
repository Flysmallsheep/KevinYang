//Code for the Measure Run page.


//Task2: Location detection and tracking

let GPSaccuracy = 20; //GPS accuracy has to be less than 20 meters
const R = 6371393; //R constant
const RAD = Math.PI/180; // Radian constant
var haveGenerateDestination = false; //Check if the destination is generated or not 
var isStarted = false; //Check if the run is started or not 
var timer = 0; // the id of setInterval
var startLocationMarker; // the marker of start location
var currentLocationMarker; // the marker of current location
var destinationLocationMarker; // the marker of destination location
var currRun;

var  new_currentLocationMarker;


//display the map: 
mapboxgl.accessToken = 'pk.eyJ1IjoibWVsa2V2IiwiYSI6ImNrOXBkZ3NwdTA5emczbG8xbDJqd3k5cXYifQ.JhqhTRKqCIGpEBOSKvpKUw';
var map = new mapboxgl.Map({
	container: 'map', 						     // container id:<div id='map'></div>
	style: 'mapbox://styles/mapbox/streets-v10', // stylesheet location:css
	zoom: 16,									 // starting zoom
	center: [145.0420733, -37.8770097] 				 // starting position [lng, lat]
	});




//track user location:
if(navigator.geolocation){
	
	currentLocation = setInterval(navigator.geolocation.watchPosition(success), 1000);//After 1s,  the callback function is invoked, please see below
}

	
function success(position){
	
	currentLat = position.coords.latitude;
	currentLng = position.coords.longitude;
	currentLocation = [currentLng,currentLat];
	
	// output accuracy
	// console.log(position.coords.accuracy)
	if(position.coords.accuracy > GPSaccuracy){
		// clearInterval(timer);
		// navigator.geolocation.clearWatch(timer);
		displayMessage("You have to increase your GPS accuracy in order to track your location!");
		// return ;
	}
	
	//Move the camera to current Location:
	map.panTo(currentLocation);
	//update the current location coordinate onto the webpage:
	document.getElementById("curLocation").innerHTML = currentLocation.toString();

	// If the destination is generated and get the distance constantly:
	if(isStarted){
		currentLocationMarker = new mapboxgl.Marker({color: "black"})
			.setLngLat(currentLocation)
			.addTo(map);
		// update the distance
		distance = calculateDistance(currentLocation, destinationLocation);
		document.getElementById("distanceHTML").innerHTML = distance.toString();
		
		
		// complete the run when distance less than 10m.
		if(distance <= 10){
			// clearInterval(timer);
			console.log("ccccccccccc");
			
			navigator.geolocation.clearWatch(timer);
			currRun.endCurrentRun();
			document.getElementById("time").innerText = currRun.getTime();
			document.getElementById("distance").innerText = currRun.getDistance();
			document.querySelector('dialog').showModal();
			displayMessage("Complete current run! ");
			document.getElementById("saveBtn").disabled = false;
		}
		currRun.accuDistance(calculateDistance(oldLocation, currentLocation));
		oldLocation = currentLocation;
		}else{
		startLocationMarker = startLocationMarker.remove();
			
			
		//put a marker on current location:
		startLocationMarker = new mapboxgl.Marker({color: "green"})
			.setLngLat(currentLocation)
			.addTo(map);
		oldLocation = currentLocation;
		//If the destination is generated, then calculate the distance
		
	}

	
}
	




//Task3 : Destination generation and display:

//1.This function should return a lnglat object called: destinationLocation
//2.The destination is displayed on the map
//3.The distance from currentLocation to destinationLocation  is displayed on the webpage (constantly updating)
//4.check if the destination is lower than 60m or bigger than 150m, then generate a new destination until the requirement is meet.      
// generate the random destination:
function randomDestination(){ 
	
	destinationLng = Math.random()*0.002 - 0.001 + currentLocation[0];
	destinationLat = Math.random()*0.002 - 0.001 + currentLocation[1];
	destinationLocation = [destinationLng,destinationLat];
	window.alert("Random destination is generated!");
	document.getElementById("curDestination").innerHTML = destinationLocation.toString();
	destinationLocationMarker = new mapboxgl.Marker({color: "red"})
			.setLngLat(destinationLocation)
			.addTo(map);
	haveGenerateDestination = true;

	distance = calculateDistance(currentLocation, destinationLocation);
	if(distance < 60 || distance > 150){

		window.alert("Smaller Than 60 Or Larger Than 150! Please refresh the page and try it again!");
		location.reload();
	}
	document.getElementById("distanceHTML").innerHTML = distance.toString();

	document.getElementById("beginBtn").disabled = false;
}


// Use Haversine formula to calculate the distance btw start and destination:
function calculateDistance(curr, dest){
	
	let P1 = curr[1] * RAD;
	let P2 = dest[1] * RAD;
	let DeltaLat = (dest[1] - curr[1]) * RAD;
	let DeltaLng = (dest[0] - curr[0]) * RAD;
	let cofA = Math.sin(DeltaLat/2) * Math.sin(DeltaLat/2) + Math.cos(P1) * Math.cos(P2) * Math.sin(DeltaLng/2)*Math.sin(DeltaLng/2);
	let cofC = 2 * Math.atan2(Math.sqrt(cofA), Math.sqrt(1-cofA));
	distance = R * cofC;
	return distance.toFixed(1);
}
 


//Task4: Beginning a run
function beginToRun(){

    startLng = startLocationMarker.getLngLat().lng;
    startLat = startLocationMarker.getLngLat().lat;
	startLocation = [startLng, startLat];
    isStarted = true;
	displayMessage("Begin The Run!");
    document.getElementById("beginBtn").disabled = true;
    document.getElementById("destBtn").disabled = true;
}

//Task6: Persistent storage of Runinstances
function saveRun(){
    var curLocation, curDestination, distanceHTML;
    curLocation = document.getElementById("curLocation").value;
    curDestination = document.getElementById('curDestination').value;
    distanceHTML = document.getElementById('distanceHTML').value;
                     
                    var now1 = new Date();
                    var timestamp1 = now1.getTime();
                    var convert1 = new Date(timestamp1)
                    var hour1 = convert1.getHours();

                    var min1 = convert1.getMinutes();
                    var sec1 = convert1.getSeconds();
                    var months1 = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
                    var dd1 = String(now1.getDate()).padStart(1, '0');
                    var mm1 = String(now1.getMonth()).padStart(1, '0');
                    var yyyy1 = now1.getFullYear();
                    
                    if (hour1 < 12) {
                        var hourDisplay1 = String(hour1) + ' am'
                    } else if (hour1 == 12) {
                        var hourDisplay1 = String(hour1) + ' pm'
                    } else if (hour1 >= 12) {
                        var hourDisplay1 = String(hour1 - 12) + ' pm'
                    }
                    //The IF statement below is aiming to add zero before the hour if the hour is a single number.
                    if(String(hour1).length===1){
                        hour1='0'+String(hour1)
                    }
                    if(String(min1).length===1){
                        min1='0'+String(min1)
                    }
                    if(String(sec1).length===1){
                        sec1='0'+String(sec1)
                    }
                    now1 = dd1 + ' ' + months1[mm1] + '.'
                    var saveddate = {
                        timestemp: timestamp1,
                        time: hour1 + ':' + min1 + ':' + sec1,
                        hour: hourDisplay1,
                        date: now1,
                        year: now1 + yyyy1
                    }
                    start(null, curDestination, curLocation, distanceHTML, startdate, null, saveddate);
                    displayMessage("save the run");
      
}
function start(currLocation, destinationLocation, currentLocation, TTdistance, arrary_Locations, time_Completed, savedtime ){
    var Runlist = new Run(currLocation, destinationLocation, currentLocation, TTdistance, arrary_Locations, time_Completed, savedtime)
    if (localStorage.getItem("monash.mcd4290.runChallengeApp")===null){
        Runlist.storeCurrentRun(Runlist.getListOfRun())
    }else{
       var PreList = JSON.parse(localStorage.getItem("monash.mcd4290.runChallengeApp"))
        PreList.push(Runlist)
        Runlist.resetList(PreList)
        Runlist.saveLocalStorage(PreList)
    }
    
}

function closeDialog(){
	document.querySelector('dialog').close();
}
