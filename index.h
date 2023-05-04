const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <title>Update Light</title>
  <script>
    function updateLight() {
      var xhr = new XMLHttpRequest();
      var url = "/update?light";
      xhr.open("GET", url);
      xhr.send();
    }
    
    function updateWaterLevel() {
      var xhr = new XMLHttpRequest();
      var url = "/getSensorData";
      xhr.onreadystatechange = function() {
        if (xhr.readyState === XMLHttpRequest.DONE) {
          if (xhr.status === 200) {
            var response = JSON.parse(xhr.responseText);
            var waterLevel = response.waterLevel;
            var moisture = response.moisture;
            document.getElementById("waterlevel").innerHTML = "Water level: " + waterLevel;
            document.getElementById("moisture").innerHTML = "Moisture: " + moisture;
          } else {
            console.log('Error: ' + xhr.status);
          }
        }
      };
      xhr.open("GET", url, true);
      xhr.send();
    }
    
    // Update water level every 5 seconds
    setInterval(updateWaterLevel, 5000);
  </script>
</head>
<body>
  <button onclick="updateLight()">Switch light</button>
  <p id="waterlevel">Water level:</p>
  <p id="moisture">Moisture:</p>
</body>
</html>

)=====";