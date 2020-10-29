// Code for the View Run page.

// The following is sample code to demonstrate navigation.
// You need not use it for final app.
//display the map: 
mapboxgl.accessToken = 'pk.eyJ1IjoibWVsa2V2IiwiYSI6ImNrOXBkZ3NwdTA5emczbG8xbDJqd3k5cXYifQ.JhqhTRKqCIGpEBOSKvpKUw';
var map = new mapboxgl.Map({
	container: 'map', 						     // container id:<div id='map'></div>
	style: 'mapbox://styles/mapbox/streets-v10', // stylesheet location:css
	zoom: 16,									 // starting zoom
	center: [145.0420733, -37.8770097] 				 // starting position [lng, lat]
	});
var NcurrentLocationMarker;
var NdestinationLocationMarker;
var new_currentLocationMarker;
var new_destinationLocationMarker;
var NewRlist = new Run;

var runIndex = localStorage.getItem("monash.mcd4290.runChallengeApp");
if (runIndex !== null)
{
    // If a run index was specified, show name in header bar title. This
    // is just to demonstrate navigation.  You should set the page header bar
    // title to an appropriate description of the run being displayed.
    var runNames = [ "First Run", "Second Run" ];
    document.getElementById("headerBarTitle").textContent = runNames[runIndex];
}


if (localStorage.getItem("monash.mcd4290.runChallengeApp") === null||localStorage.getItem("monash.mcd4290.runChallengeApp")[0]===null) {
    alert('There is no RUN inside,please add some observation first!')}
    if (runIndex=0 || 1){
    var nn_run = JSON.parse(localStorage.getItem("monash.mcd4290.runChallengeApp"))
    showpoint(runIndex);
    }
    
    function showpoint(index1)
{
map.panTo(nn_run[index1]._startLocation);
document.getElementById("curLocation").innerHTML = firstrun[index1]._startLocation.toString();
NcurrentLocationMarker = new mapboxgl.Marker({color: "blcak"})
			.setLngLat(nn_run[index1]._startLocation)
			.addTo(map);
NdestinationLocationMarker = new mapboxgl.Marker({color: "read"})
			.setLngLat(nn_run[index1]._destinationLocation)
			.addTo(map); 
    var refdistance = document.getElementById("distanceHTML");
    refdistance.innerHTML = nn_run[index1]._Tdistance;
}

    function deleteRUN(index) { //delete the first index
    
    if (confirm("Do you want to remove this run? ")) {
        var ReadOb=[];
        ReadOb.splice(index, 1);
        localStorage.setItem("monash.mcd4290.runChallengeApp", JSON.stringify(ReadOb))
        NewRlist.resetList(ReadOb)
        displayMessage('The Run has been removed already!');
    }
        location.href(index.html);
    }

function reattmept(){
location.href='newRun.html';
    
	var New_currentLocation = [145.1362485, -37.9105599];

    var New_destinationLng = Math.random()*0.002 - 0.001 + NEW_currentLocation[0];
	var New_destinationLat = Math.random()*0.002 - 0.001 + NEW_currentLocation[1];
	var New_destinationLocation = [destinationLng,destinationLat];
    new_destinationLocationMarker = new mapboxgl.Marker({color: "blue"})
			.setLngLat(New_destinationLocation)
			.addTo(map);
    displayMessage("this is your new destination, you should run to");
    
}
