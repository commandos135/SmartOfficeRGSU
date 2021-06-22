char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="fr" class="">
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
      <meta name="viewport" content="width=device-width,initial-scale=1,user-scalable=no">
      <title>Menu principal</title>
      <style>div,fieldset,input,select{padding:5px;font-size:1em;}fieldset{background:#4f4f4f;}p{margin:0.5em 0;}input{width:100%;box-sizing:border-box;-webkit-box-sizing:border-box;-moz-box-sizing:border-box;background:#dddddd;color:#000000;}input[type=checkbox],input[type=radio]{width:1em;margin-right:6px;vertical-align:-1px;}input[type=range]{width:99%;}select{width:100%;background:#dddddd;color:#000000;}textarea{resize:vertical;width:98%;height:318px;padding:5px;overflow:auto;background:#1f1f1f;color:#65c115;}body{text-align:center;font-family:verdana,sans-serif;background:#252525;}td{padding:0px;}button{border:0;border-radius:0.3rem;background:#1fa3ec;color:#faffff;line-height:2.4rem;font-size:1.2rem;width:100%;-webkit-transition-duration:0.4s;transition-duration:0.4s;cursor:pointer;}button:hover{background:#0e70a4;}.bred{background:#d43535;}.bred:hover{background:#931f1f;}.bgrn{background:#47c266;}.bgrn:hover{background:#5aaf6f;}a{color:#1fa3ec;text-decoration:none;}.p{float:left;text-align:left;}.q{float:right;text-align:right;}.r{border-radius:0.3em;padding:2px;margin:6px 2px;}</style>
   </head>
   <body>
      <div style="text-align:left;display:inline-block;color:#eaeaea;min-width:340px;">
         <div style="text-align:center;color:#eaeaea;">
            <noscript>Pour utiliser Tasmota, veuillez activer JavaScript<br></noscript>
            <h2>Menu principal</h2><br>
         </div>
       <div id="l1" name="l1">
            <table style="width:100%"></table>
            <table style="width:100%">
               <tbody>
                  <tr>
                     <td style="width:33%">
                        <div id="0" style="text-align:center;font-weight:normal;font-size:33px">&nbsp;</div>
                     </td>
                     <td style="width:33%">
                        <div id="1" style="text-align:center;font-weight:normal;font-size:33px">&nbsp;</div>
                     </td>
                  <td style="width:33%">
                        <div id="2" style="text-align:center;font-weight:normal;font-size:33px">&nbsp;</div>
                     </td>
                   
                  </tr>
               </tbody>
            </table>
         </div>
         <table style="width:100%">
            <tbody>
               <tr>
                  <td style="width:33%"><button onclick="Data1();" name="">Fan 1</button></td>
                  <td style="width:33%"><button onclick="Data2();" name="">Fan 2</button></td>
                  <td style="width:33%"><button onclick="Data3();" name="">Led</button></td>
                  
               </tr>
            </tbody>
         </table><br>
         <p></p>
         <form action="/wifi" method="get"><button name="">Configuration WiFi</button></form>
         <p></p>
         <p></p>
         <form action="/mqtt" method="get"><button name="">Configuration MQTT</button></form>
         <p></p>
         <p></p>
         <form action="/ipconf" method="get"><button name="">Configuration IP Adresse</button></form>
         <p></p>
         <p></p>
         <form action="/miseajour" method="get"><button name="">Mise à jour</button></form>
         <p></p>
         <p></p>
         <form action="/info" method="get"><button name="">Information</button></form>
         <p></p>
         <div></div>
         <p></p>
         <form action="/redemarrer" method="get" onsubmit="return confirm(&quot;Confirmer la redémarrage.&quot;);"><button name="non" class="button bred">Redémarrer</button></form>
         <p></p>
         <p></p>
         <form action="/reinit" method="get" onsubmit="return confirm(&quot;Confirmer la réinit. de la config.&quot;);"><button name="non" class="button bred">Configuration par défaut</button></form>
         <p></p>
         <div></div>
         <div style="text-align:center;font-size:14px;">
            <hr>
            <a target="_blank" style="color:#aaa;"><b>Par Wassim.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Copyrights© 2021 - All Rights Reserved.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Made With <span style="color: #e25555;">&#10084;</span> In Tunisie.</b></a><br>
      </div>
   </body>
   <script language="javascript">
function Data1() {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "toggle1", true);
  xhttp.send();
}
function Data2() {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "toggle2", true);
  xhttp.send();
}
function Data3() {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "toggle3", true);
  xhttp.send();
}

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var res = this.responseText.split("/");
      
  document.getElementById("0").innerHTML = res[0];
  document.getElementById("1").innerHTML = res[1];
  document.getElementById("2").innerHTML = res[2];

    }
  };
  xhttp.open("GET", "bb", true);
  xhttp.send();
}
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 500); //2000mSeconds update rate            

</script>
</html>
)=====";
