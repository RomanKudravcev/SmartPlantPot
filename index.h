const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <!-- Meta tags -->
  <meta charset="utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
  <meta content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0" name="viewport" />
  <meta name="viewport" content="width=device-width" />

  <style media="screen">
    .loader {
      margin: auto;
      padding: auto;
      border: 16px solid #333; /* Light grey */
      border-top: 16px solid #3498db; /* Blue */
      border-radius: 50%;
      position: relative;
      top: calc(50% - 60px);
      width: 120px;
      height: 120px;
      animation: spin 2s linear infinite;
      }

      @keyframes spin {
      0% { transform: rotate(0deg); }
      100% { transform: rotate(360deg); }
    }

    #preloader {
      position: absolute;
      z-index: 999;
      width: 100%;
      height: 100%;
      background: rgba(0, 0, 0, 0.8);
    }
  </style>

  <!-- Favicon and title -->
  <title>Pflanze</title>
  <script src="https://code.jquery.com/jquery-latest.js"></script>
  <script type="text/javascript">
    //========== CONFIG ==========

    var ip_adr = $(location).attr('hostname');
    console.log(ip_adr);


    function get_data() {

      $.ajax("http://" + ip_adr + "/api/waterlevel", {
        success: function (data, status, xhr) {
          $("#id_waterlevel").html(data);
          $("#bar_waterlevel").css("width", data + "%");

          if (data > 60) {
            $("#bar_waterlevel").attr("class", "progress-bar bg-success");
          } else if (data < 60 && data > 30) {
            $("#bar_waterlevel").attr("class", "progress-bar bg-secondary");
          } else {
            $("#bar_waterlevel").attr("class", "progress-bar bg-danger");
          }
        }
      });






      $.ajax("http://" + ip_adr + "/api/bfs", {
        success: function (data, status, xhr) {
          $("#id_bfs").html(data);
          $("#bar_bfs").css("width", data + "%");
        }
      });







      $.ajax("http://" + ip_adr + "/api/light", {
        success: function (data, status, xhr) {
          if (data == 1) {
            $("#img_light").attr("src", "https://img.icons8.com/color/96/000000/light.png");
          } else {
            $("#img_light").attr("src", "https://img.icons8.com/color/96/000000/light-off.png");
          }
        }
      });


      $.ajax("http://" + ip_adr + "/api/btn_perm", {
        success: function (data, status, xhr) {
          if (data == 0) {
            $("#id_light").html("Auto");
            $("#id_light").attr("class", "badge badge-primary");
          } else if (data == 1) {
            $("#id_light").html("Aus");
            $("#id_light").attr("class", "badge badge-danger");
          } else if (data == 2) {
            $("#id_light").html("An");
            $("#id_light").attr("class", "badge badge-success");
          }
        }
      });



      $.ajax("http://" + ip_adr + "/api/btn_day", {
        success: function (data, status, xhr) {
          if (data == 0) {
            $("#id_light_day").html("24h");
            $("#id_light_day").attr("class", "badge");
          } else if (data == 1) {
            $("#id_light_day").html("Aktiv");
            $("#id_light_day").attr("class", "badge badge-success");
          }
        }
      });



  id_light_day


    }


  </script>

  <!-- Halfmoon CSS -->
  <link href="https://cdn.jsdelivr.net/npm/halfmoon@1.1.1/css/halfmoon.min.css" rel="stylesheet" />
  <!--
    Or,
    Use the following (CSS file with variables):
    <link href="https://cdn.jsdelivr.net/npm/halfmoon@1.1.1/css/halfmoon-variables.min.css" rel="stylesheet" />
    Learn more: https://www.gethalfmoon.com/docs/customize/#notes-on-browser-compatibility
  -->
</head>
<body class="with-custom-webkit-scrollbars with-custom-css-scrollbars" data-dm-shortcut-enabled="true" data-set-preferred-mode-onload="true">




  <!-- Modals go here -->
  <!-- Reference: https://www.gethalfmoon.com/docs/modal -->

  <!-- Page wrapper start -->
  <div class="page-wrapper with-navbar">

    <!-- Navbar start -->
    <nav class="navbar justify-content-between">
      <a href="" class="navbar-brand">
        <img src="https://img.icons8.com/doodle/96/000000/plant-under-sun--v1.png"/>
        Dashboard
      </a>

    </nav>
    <!-- Navbar end -->

    <!-- Content wrapper start -->
    <div class="content-wrapper">





      <div class="content">
        <h2 class="content-title">
          Wasserstand
        </h2>

        <div class="progress-group">
          <img width="40em" src="https://img.icons8.com/color/96/000000/water.png"/>
          <div class="progress">
            <div class="progress-bar" id="bar_waterlevel" role="progressbar" style="width: 50%;" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100"></div>
          </div>
          <span class="progress-group-label"><span id="id_waterlevel">0</span>%</span>
        </div>

      </div>








      <div class="content">
        <h2 class="content-title">
          Bodenfeuchtigkeit
        </h2>

        <div class="progress-group">
          <img width="40em" src="https://img.icons8.com/plasticine/100/000000/potted-plant.png"/>
          <div class="progress">
            <div class="progress-bar" id="bar_bfs" role="progressbar" style="width: 50%;" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100"></div>
          </div>
          <span class="progress-group-label"><span id="id_bfs">0</span>%</span>
        </div>

      </div>








      <div class="content">
        <h2 class="content-title">
          Beleuchtung
        </h2>

        <div class="container-fluid text-center">
          <div class="row">

            <div class="col" id="id_light_toggle_perm">
              <img width="50em" id="img_light" src="https://img.icons8.com/color/96/000000/light-off.png"/>
              <br><span class="badge badge-succes" id="id_light">An</span>
            </div>

            <div class="col" id="id_light_toggle_day">
              <img width="50em" id="img_light_day" src="https://img.icons8.com/pastel-glyph/64/4a90e2/alarm-clock--v3.png"/>
              <br><span class="badge badge-succes" id="id_light_day">24h</span>
            </div>


          </div>
        </div>

      </div>











    </div>
    <!-- Content wrapper end -->

  </div>
  <!-- Page wrapper end -->

  <!-- Halfmoon JS -->
  <script src="https://cdn.jsdelivr.net/npm/halfmoon@1.1.1/js/halfmoon.min.js"></script>
  <script type="text/javascript">
  get_data();
  setInterval(function(){
    get_data();
  }, 2000);



  $("#id_light_toggle_perm").click(function() {
    $.get("http://" + ip_adr + "/api/write/btn_perm");
  });

  $("#id_light_toggle_day").click(function() {
    $.get("http://" + ip_adr + "/api/write/btn_day");
  });



  </script>
</body>
</html>
)=====";