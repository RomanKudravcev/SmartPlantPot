const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
    <meta
      content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0"
      name="viewport"
    />
    <meta name="viewport" content="width=device-width" />

    <!-- Halfmoon CSS -->
    <link
      href="https://cdn.jsdelivr.net/npm/halfmoon@1.1.1/css/halfmoon.min.css"
      rel="stylesheet"
    />

    <!-- Dark mode CSS -->
    <link
      href="https://cdn.jsdelivr.net/npm/halfmoon@1.1.1/css/halfmoon-dark.min.css"
      rel="stylesheet"
    />

    <title>PlantPot</title>
    <script>
      function updateLight() {
        document.querySelector(".spinner-overlay").style.display = "flex";
        var xhr = new XMLHttpRequest();
        var url = "/update?light";
        xhr.open("GET", url);
        xhr.send();
      }

      function getData() {
        var xhr = new XMLHttpRequest();
        var url = "/getSensorData";
        xhr.onreadystatechange = function () {
          if (xhr.readyState === XMLHttpRequest.DONE) {
            if (xhr.status === 200) {
              var response = JSON.parse(xhr.responseText);
              var waterLevel = response.waterLevel;
              var moisture = response.moisture;
              var light = response.light;
              document.getElementById("waterlevel").innerHTML = waterLevel;
              document.getElementById("moisture").innerHTML = moisture;
              document.getElementById("bar-waterlevel").style.width =
                waterLevel + "%";
              document.getElementById("bar-moisture").style.width =
                moisture + "%";

              if (light == true) {
                document.getElementById("light").innerHTML = "Light on";
                document.getElementById("light-bulb").src =
                  "https://img.icons8.com/color/96/000000/light-on.png";
              } else {
                document.getElementById("light").innerHTML = "Light off";
                document.getElementById("light-bulb").src =
                  "https://img.icons8.com/color/96/000000/light-off.png";
              }
              document.querySelector(".spinner-overlay").style.display = "none";
            } else {
              console.log("Error: " + xhr.status);
            }
          }
        };
        xhr.open("GET", url, true);
        xhr.send();
      }

      // getData every 5 seconds
      setInterval(getData, 5000);
    </script>
    <style>
      .btn {
        height: 120px;
      }
      .spinner-overlay {
        position: fixed;
        top: 0;
        right: 0;
        bottom: 0;
        left: 0;
        background-color: rgba(0, 0, 0, 0.7);
        display: flex;
        align-items: center;
        justify-content: center;
        z-index: 9999;
      }

      .spinner {
        display: inline-block;
        width: 50px;
        height: 50px;
        border: 3px solid rgba(255, 255, 255, 0.3);
        border-radius: 50%;
        border-top-color: #fff;
        animation: spin 1s ease-in-out infinite;
      }

      @keyframes spin {
        to {
          -webkit-transform: rotate(360deg);
          transform: rotate(360deg);
        }
      }
    </style>
  </head>
  <body
    class="with-custom-webkit-scrollbars with-custom-css-scrollbars dark-mode"
    data-dm-shortcut-enabled="true"
    data-set-preferred-mode-onload="true"
  >
    <!-- Page wrapper start -->
    <div class="page-wrapper with-navbar">
      <!-- Navbar start -->
      <nav class="navbar justify-content-between">
        <a href="" class="navbar-brand">
          <img
            src="https://img.icons8.com/doodle/96/000000/plant-under-sun--v1.png"
          />
          Smart Plantpot.
        </a>
      </nav>
      <!-- Navbar end -->

      <!-- Content wrapper start -->
      <div class="content-wrapper">
        <div class="content" style="padding-top:50px">
          <h2 class="content-title">Waterlevel</h2>
          <div class="progress-group">
            <img
              width="40em"
              src="https://img.icons8.com/color/96/000000/water.png"
            />
            <div class="progress h-25">
              <div
                class="progress-bar"
                id="bar-waterlevel"
                role="progressbar"
                aria-valuenow="100"
                aria-valuemin="0"
                aria-valuemax="100"
              ></div>
            </div>
            <span class="progress-group-label"
              ><span id="waterlevel">0</span>%</span
            >
          </div>
        </div>

        <div class="content" style="padding-top:50px">
          <h2 class="content-title">Moisture</h2>
          <div class="progress-group">
            <img
              width="40em"
              src="https://img.icons8.com/plasticine/100/000000/potted-plant.png"
            />
            <div class="progress h-25">
              <div
                class="progress-bar"
                id="bar-moisture"
                role="progressbar"
                aria-valuenow="100"
                aria-valuemin="0"
                aria-valuemax="100"
              ></div>
            </div>
            <span class="progress-group-label"
              ><span id="moisture">0</span>%</span
            >
          </div>
        </div>

        <div class="content d-flex align-items-center justify-content-center" style="padding-top:80px">
          <button
            class="btn d-flex flex-column align-items-center justify-content-center"
            onclick="updateLight()"
          >
            <div class="content">
              <img
                id="light-bulb"
                src="https://img.icons8.com/color/96/000000/light-off.png"
                alt="your image"
                width="50"
                height="50"
              />
              <p id="light" style="margin: 0px">Light off</p>
            </div>
          </button>
          <div class="spinner-overlay" style="display: none">
            <div class="spinner"></div>
          </div>
        </div>
      </div>
      <!-- Content wrapper end -->
    </div>

    <!-- Page wrapper end -->
  </body>
</html>
)=====";