// Code for the main app page (Past Runs list).

// The following is sample code to demonstrate navigation.
// You need not use it for final app.

var NEW_RUNLis = new Run

if (localStorage.getItem("monash.mcd4290.runChallengeApp") === null||localStorage.getItem("monash.mcd4290.runChallengeApp")[0]===null) {
    alert('There is no RUN inside,please add some observation first!')
} else {
    NEW_RUNList = JSON.parse(localStorage.getItem("monash.mcd4290.runChallengeApp"))
    }
 var refdate = document.getElementById("datetime");
    var refdate2 = document.getElementById("datetime2");
    
    var SEC_refdate = document.getElementById("SEC_datetime");
    var SEC_refdate2 = document.getElementById("SEC_datetime2");
    var i=NEW_RUNList.length-1;//the length of array, i is the last RUN data
         //first run
        refdate.innerHTML = NEW_RUNList[i-1]._timechecked.date1;
        refdate2.innerHTML = NEW_RUNList[i-1]._timechecked.time1;
         //Second run
        SEC_refdate.innerHTML = NEW_RUNList[i]._timechecked.date1;
        SEC_refdate2.innerHTML = NEW_RUNList[i]._timechecked.time1;





function viewRun(runIndex)
{
    // Save the desired run to local storage so it can be accessed from View Run page.
    localStorage.setItem("monash.mcd4290.runChallengeApp", runIndex);
    // ... and load the View Run page.
    location.href = 'viewRun.html';
}

