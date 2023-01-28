const char MAIN_PAGE_IDREAMS[] PROGMEM = R"=====(
<html lang="en">
<head>
	<base target="_top">
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link href="data:image/x-icon;base64,AAABAAEAEBAAAAAAAABoBQAAFgAAACgAAAAQAAAAIAAAAAEACAAAAAAAAAEAAAAAAAAAAAAAAAEAAAAAAAAAAAAA3cWnABV/NgDHml4AyZpeAMyfZABDrWQA1biTAMCMRwDKo3AACnUrADaZVgDXvZkAR7hqACaKRQDDlFYAwpVZAD+lXwDYr3kA5cScAErMcADHm2IALpBOAEXbcADesXYAv4xIAAh0KQDUuZcARrRoAM6mcQC+kVcAw5NUANGrdwDRrHoAzq2GAErFbgAtj0wAxZxmAEnPcQDeyawAPeluANS0iQDfy7IA7+HPANi3iQDry6AA7+PVAEWwZgDpz6wAvo5PADJ3MgBHt2kAw5JSAGuYXQDbxKcAxphbAMWaYQAAbiIA4cakAFGUWwDTtIoAjYdOAMyeZAAtdjAAzqFkALeOWQDHxaIAzqJnAOfStgBEjVAAwpFQAMKTVgDAlVwA3MGfAMWWVgDYq3AA6tvIAEjOcADbsHYA7uDOAO/gzgDIn2gA48urAMigawDizbEARK9lAOHOtADOoWUAvoxLACuoUQDXu5cA59K3AMGRUQDq07EA06ZrAMORUQDXqm4A2sSpAMaXWgDfxaMAIHgvAMmcYADKnGAARN1xAN7KsgDgs3cA2LaJANa5kgAueC8AmopHANKmbADbvpgAwZJVANrBoQDfwZgAC4cwAMOZYQDarnIA1K9+AN7HqgDJm14A5MikANK0jQDs4NAAA3ElAD7obwDhzLAA37R7AOHOtgAKcigARbJnALi0jgDk07wA5tK5AMKQUADZvpkAc41JANjBogDFlVYA6drIAEyTXABKynAAQapiAOXPsQDl0roAwJBRAL+RVADGkUsA6Lt/AMOUVADWqW4AxJZaAIiEQQCtiUYA6NrJAObfzwDIml0A7d7MAEXccQAEdCcA5cypADOVUgDVupgAwI5MADaZVQDFkEkAxJRVAMWUVQDOq34A59jEAM2thADDl14ASsNvAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAApZOTpQAAAAAAAAAAAAAsOo9bRDmBagAAAAAAAAAhHQOnX4ZtOTkgAAAAAACjRh+mikqVNDk5OQgAAACjXA9inHgEbCShpAs5GQAAkUc3ZgVXQAKOLxyCBpkAMXCXZUNeYJaIIxQmjZhYWKtTFT5udWkYS54ofZ+SOBAlayl2En+UZE45c1EJqDx0SAFJY3k1OS0Tcm+HDFpxHgAHfoU5Ql0woFJUkFYnegAAIndFOTtQK0+dTKmENqoAAACiDhYaOQqMLnuLKhsAAAAAAIOCDTNVEZuagIkAAAAAAAAATRdnWax8aGEAAAAAAAAAAAAAPT8yQQAAAAAAAPw/AADwDwAA4AcAAMADAACAAQAAgAEAAAAAAAAAAAAAAAAAAAAAAACAAQAAgAEAAMADAADgBwAA8A8AAPw/AAA=" rel="icon" type="image/x-icon" />
	<title>E5MAT: LoRa GPS Tracker</title>
    <link rel="stylesheet" href="https://unpkg.com/leaflet@1.9.3/dist/leaflet.css" integrity="sha256-kLaT2GOSpHechhsozzB+flnD+zUyjE2LlfWPgU04xyI=" crossorigin=""/>
    <script src="https://unpkg.com/leaflet@1.9.3/dist/leaflet.js" integrity="sha256-WBkoXOwTeyKclOHuWtc+i2uENFpDZ9YPdf5Hf+D7ewM=" crossorigin=""></script>
	<style>
		html, body {
			height: 100%;
			margin: 0;
		}
		.leaflet-container {
			height: 400px;
			width: 600px;
			max-width: 100%;
			max-height: 100%;
		}
		img.huechange { filter: hue-rotate(240deg); }
		img.huecchange { filter: hue-rotate(140deg); }
	</style>
	<style>body { padding: 0; margin: 0; } #map { height: 100%; width: 100vw; }</style>
</head>
<body>
<div id='map'></div>
<script>
	setInterval(function() {
	  // Call a function repetatively with 2 Second interval
	  getGPSData();
	}, 2000); //2000 mSeconds update rate
//-----------------------------------------------------
  var PhoneIcon = L.icon({
    iconUrl: 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAgAAAAIACAYAAAD0eNT6AAAACXBIWXMAAAsTAAALEwEAmpwYAAAHQmlUWHRYTUw6Y29tLmFkb2JlLnhtcAAAAAAAPD94cGFja2V0IGJlZ2luPSLvu78iIGlkPSJXNU0wTXBDZWhpSHpyZVN6TlRjemtjOWQiPz4gPHg6eG1wbWV0YSB4bWxuczp4PSJhZG9iZTpuczptZXRhLyIgeDp4bXB0az0iQWRvYmUgWE1QIENvcmUgNS42LWMxNDggNzkuMTY0MDM2LCAyMDE5LzA4LzEzLTAxOjA2OjU3ICAgICAgICAiPiA8cmRmOlJERiB4bWxuczpyZGY9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkvMDIvMjItcmRmLXN5bnRheC1ucyMiPiA8cmRmOkRlc2NyaXB0aW9uIHJkZjphYm91dD0iIiB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iIHhtbG5zOnhtcE1NPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvbW0vIiB4bWxuczpzdEV2dD0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL3NUeXBlL1Jlc291cmNlRXZlbnQjIiB4bWxuczpwaG90b3Nob3A9Imh0dHA6Ly9ucy5hZG9iZS5jb20vcGhvdG9zaG9wLzEuMC8iIHhtbG5zOmRjPSJodHRwOi8vcHVybC5vcmcvZGMvZWxlbWVudHMvMS4xLyIgeG1wOkNyZWF0b3JUb29sPSJBZG9iZSBQaG90b3Nob3AgMjEuMCAoV2luZG93cykiIHhtcDpDcmVhdGVEYXRlPSIyMDIyLTA2LTA3VDE4OjQ1OjMyKzAyOjAwIiB4bXA6TWV0YWRhdGFEYXRlPSIyMDIyLTA2LTA5VDIxOjU2OjU1KzAyOjAwIiB4bXA6TW9kaWZ5RGF0ZT0iMjAyMi0wNi0wOVQyMTo1Njo1NSswMjowMCIgeG1wTU06SW5zdGFuY2VJRD0ieG1wLmlpZDpkNTRlNDFkNy0wMWQyLWI3NGUtOGVkYS0wNDY4Yzg3NzdiYmUiIHhtcE1NOkRvY3VtZW50SUQ9ImFkb2JlOmRvY2lkOnBob3Rvc2hvcDpjZmM0MThiYS02YzQ3LTg4NGQtYjY0NS0zNDFkNGRhM2VmNjEiIHhtcE1NOk9yaWdpbmFsRG9jdW1lbnRJRD0ieG1wLmRpZDo1ODBhYTE4MS1iNTc0LTBlNDUtOTA4OS05Mzk4OWQ0NDFkOTEiIHBob3Rvc2hvcDpDb2xvck1vZGU9IjMiIHBob3Rvc2hvcDpJQ0NQcm9maWxlPSJzUkdCIElFQzYxOTY2LTIuMSIgZGM6Zm9ybWF0PSJpbWFnZS9wbmciPiA8eG1wTU06SGlzdG9yeT4gPHJkZjpTZXE+IDxyZGY6bGkgc3RFdnQ6YWN0aW9uPSJjcmVhdGVkIiBzdEV2dDppbnN0YW5jZUlEPSJ4bXAuaWlkOjU4MGFhMTgxLWI1NzQtMGU0NS05MDg5LTkzOTg5ZDQ0MWQ5MSIgc3RFdnQ6d2hlbj0iMjAyMi0wNi0wN1QxODo0NTozMiswMjowMCIgc3RFdnQ6c29mdHdhcmVBZ2VudD0iQWRvYmUgUGhvdG9zaG9wIDIxLjAgKFdpbmRvd3MpIi8+IDxyZGY6bGkgc3RFdnQ6YWN0aW9uPSJzYXZlZCIgc3RFdnQ6aW5zdGFuY2VJRD0ieG1wLmlpZDoyN2ZmY2ZkOC1iYmVkLTMwNDUtYjM2Yi1hMDM3ZGYxMjc2NmMiIHN0RXZ0OndoZW49IjIwMjItMDYtMDdUMTg6NDU6MzIrMDI6MDAiIHN0RXZ0OnNvZnR3YXJlQWdlbnQ9IkFkb2JlIFBob3Rvc2hvcCAyMS4wIChXaW5kb3dzKSIgc3RFdnQ6Y2hhbmdlZD0iLyIvPiA8cmRmOmxpIHN0RXZ0OmFjdGlvbj0ic2F2ZWQiIHN0RXZ0Omluc3RhbmNlSUQ9InhtcC5paWQ6ZDU0ZTQxZDctMDFkMi1iNzRlLThlZGEtMDQ2OGM4Nzc3YmJlIiBzdEV2dDp3aGVuPSIyMDIyLTA2LTA5VDIxOjU2OjU1KzAyOjAwIiBzdEV2dDpzb2Z0d2FyZUFnZW50PSJBZG9iZSBQaG90b3Nob3AgMjEuMCAoV2luZG93cykiIHN0RXZ0OmNoYW5nZWQ9Ii8iLz4gPC9yZGY6U2VxPiA8L3htcE1NOkhpc3Rvcnk+IDxwaG90b3Nob3A6RG9jdW1lbnRBbmNlc3RvcnM+IDxyZGY6QmFnPiA8cmRmOmxpPjQ2NjFGODExQzRCQzc3RkI0OThFMTU4NkZE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',
    iconSize: [40, 40], //size of the icon
  });
	//let lat, lng;
	//lat = 35.64060937713156;
	//lng = 51.31699853619998;
	var prevLat, prevLong;
	var phoneLat, phoneLong;
	var zoomLevel = 16;
	var theMarker = {};
	
	const map = L.map('map').fitWorld();
	const tiles = L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
	//const tiles = L.tileLayer('https://api.mapbox.com/styles/v1/mapbox/streets-v9/tiles/{z}/{x}/{y}?access_token=YOUR_KEY', {
		maxZoom: 19,
		//attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
	}).addTo(map);
//-----------------------------------------------------
	function getGPSData() {
	  var xhttp = new XMLHttpRequest();
	  xhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
		  let text = this.responseText;
		  const myArray = text.split(",");
		  ShowMarker(myArray[0], myArray[1]);
		}
	  };
	  xhttp.open("GET", "gpsDATA", true);
	  xhttp.send();
	}
//-----------------------------------------------------	
	function ShowMarker(lat, lng) {
		if (!(isEmpty(lat)) || !(isEmpty(lng))){
			if (lat != prevLat && lng != prevLong) {
				var mapCenter = [lat,lng];
				if (theMarker != undefined) {
					  map.removeLayer(theMarker);
					  if ((prevLat != undefined) & (prevLong != undefined)) {
							theMarker = L.marker([prevLat, prevLong]).addTo(map);
							theMarker._icon.classList.add("huecchange");
					  }
				}
				if ((phoneLat != undefined) & (phoneLong != undefined)) {
					var distance = getDistanceBetweenTwoPoints(phoneLat, phoneLong, lat, lng, 'K');
					var distanceRound = Math.round(distance*1000)/1000;
					theMarker = L.marker([lat, lng]).addTo(map)
					.bindPopup('Distance from you: ' + distanceRound + ' K');
					theMarker._icon.classList.add("huechange");
					map.setView(new L.LatLng(lat, lng), zoomLevel);
					SendtoGoogleSheet(lat, lng);
					//map.flyTo(new L.LatLng(lat, lng), zoomLevel);
				
				}
				else
				{
					theMarker = L.marker([lat, lng]).addTo(map);
					theMarker._icon.classList.add("huechange");
					map.setView(new L.LatLng(lat, lng), zoomLevel);
					SendtoGoogleSheet(lat, lng);
					//map.flyTo(new L.LatLng(lat, lng), zoomLevel);
					
				}
				prevLat = lat;
				prevLong = lng;
		  }
		//prevLat = lat;
		//prevLong = lng;
	  }
	}
//-----------------------------------------------------
	function SendtoGoogleSheet(Lat, Lng){
	  const Http = new XMLHttpRequest();
		const url='https://docs.google.com/forms/d/e/1FAIpQLSdcyvFZC-Hw4fsx9qnQuoW-dgS8wmpoRtF_lvYjZAb3dBi-8g/formResponse?&submit=Submit?usp=pp_url&entry.1211826835=' + Lat + '&entry.972490377=' + Lng + '&entry.949707414=LoRaTracker1';
		Http.open("GET", url);
		Http.send();

		Http.onreadystatechange = (e) => {
		  console.log(Http.responseText);
		}

		Http.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
				  console.log(Http.responseText);
			}
		};
	}	
//-----------------------------------------------------	
	function isEmpty(value) {
	  return (
		(value == null) ||
		(value.hasOwnProperty('length') && value.length === 0) ||
		(value.constructor === Object && Object.keys(value).length === 0)
	  )
	}
//-----------------------------------------------------  
//var distance = getDistanceBetweenTwoPoints(51.5112139, -0.119824, 48.8567, 2.3508, 'K');
//round to 3 decimal places
//console.log(Math.round(distance*1000)/1000);  //displays 343.548

	function getDistanceBetweenTwoPoints(lat1, lon1, lat2, lon2, unit) {
	 if ((lat1 == lat2) && (lon1 == lon2)) {
		return 0;
	  }
	  else {
		var radlat1 = Math.PI * lat1/180;
		var radlat2 = Math.PI * lat2/180;
		var theta = lon1-lon2;
		var radtheta = Math.PI * theta/180;
		var dist = Math.sin(radlat1) * Math.sin(radlat2) + Math.cos(radlat1) * Math.cos(radlat2) * Math.cos(radtheta);
		if (dist > 1) {
		  dist = 1;
		}
		dist = Math.acos(dist);
		dist = dist * 180/Math.PI;
		dist = dist * 60 * 1.1515;
		if (unit=="K") { dist = dist * 1.609344 }
		if (unit=="N") { dist = dist * 0.8684 }
		return dist;
	  }
	}
//-----------------------------------------------------	
	function onLocationFound(e) {
		//const radius = Math.round(e.accuracy / 2);
		//const locationMarker = L.marker(e.latlng,{icon: L.divIcon({className: 'poi', html: '<b>📱</b>'})}).addTo(map);
    const locationMarker = L.marker(e.latlng, {icon: PhoneIcon}).addTo(map)
      .bindPopup('Your location is: [' + e.latlng.lat + ', ' + e.latlng.lng + ']');
      phoneLat = e.latlng.lat;
      phoneLong= e.latlng.lng;
	  //.bindPopup(`You are within ${radius} meters from this point`);
		//const locationCircle = L.circle(e.latlng, radius).addTo(map);
	}

	function onLocationError(e) {
		//alert('Please enable location permission in device settings and try again.');
		alert(e.message);
	}
	
	map.on('locationfound', onLocationFound);
	map.on('locationerror', onLocationError);
	map.locate({setView: true, maxZoom: 16});
</script>
</body>
</html>
)=====";
