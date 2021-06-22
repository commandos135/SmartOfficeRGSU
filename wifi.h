char wifi[] PROGMEM = R"=====(
<!DOCTYPE html>

<html lang="fr" class="">
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
      <meta name="viewport" content="width=device-width,initial-scale=1,user-scalable=no">
      <title>Configuration WiFi</title>
      <style>div,fieldset,input,select{padding:5px;font-size:1em;}fieldset{background:#4f4f4f;}p{margin:0.5em 0;}input{width:100%;box-sizing:border-box;-webkit-box-sizing:border-box;-moz-box-sizing:border-box;background:#dddddd;color:#000000;}input[type=checkbox],input[type=radio]{width:1em;margin-right:6px;vertical-align:-1px;}input[type=range]{width:99%;}select{width:100%;background:#dddddd;color:#000000;}textarea{resize:vertical;width:98%;height:318px;padding:5px;overflow:auto;background:#1f1f1f;color:#65c115;}body{text-align:center;font-family:verdana,sans-serif;background:#252525;}td{padding:0px;}button{border:0;border-radius:0.3rem;background:#1fa3ec;color:#faffff;line-height:2.4rem;font-size:1.2rem;width:100%;-webkit-transition-duration:0.4s;transition-duration:0.4s;cursor:pointer;}button:hover{background:#0e70a4;}.bred{background:#d43535;}.bred:hover{background:#931f1f;}.bgrn{background:#47c266;}.bgrn:hover{background:#5aaf6f;}a{color:#1fa3ec;text-decoration:none;}.p{float:left;text-align:left;}.q{float:right;text-align:right;}.r{border-radius:0.3em;padding:2px;margin:6px 2px;}.si{display:inline-flex;align-items:flex-end;height:15px;padding:0}.si i{width:3px;margin-right:1px;border-radius:3px;background-color:#eaeaea}.si .b0{height:25%}.si .b1{height:50%}.si .b2{height:75%}.si .b3{height:100%}.o30{opacity:.3}</style>
   </head>
   <body>
      <div style="text-align:left;display:inline-block;color:#eaeaea;min-width:340px;">
         <div style="text-align:center;color:#eaeaea;">
            <noscript>Pour utiliser Tasmota, veuillez activer JavaScript<br></noscript>
                      <h2>Configuration WIFI</h2><br>
         </div>
        
         <a id="ssidscan"></a>
         
         <fieldset>
            <legend><b>&nbsp;Paramètres Wifi&nbsp;</b></legend>
            
            
            <form>
            
               <p><b>AP1 SSID</b> ()<br><input id="ssid" placeholder="ssid1" value="" name="s1"></p>
               <p><label><b>Mot de passe AP1</b><input type="checkbox" onclick="sp(&quot;password&quot;)" name=""></label><br><input  id="password" type="password" placeholder="Mot de passe ssid1" value="" name="p1"></p>
               <p><b>AP2 SSId</b> ()<br><input id="ssid2" placeholder="ssid2" value="" name="s2"></p>
               <p><label><b>Mot de passe AP2</b><input type="checkbox" onclick="sp(&quot;password2&quot;)" name=""></label><br><input id="password2" type="password" placeholder="Mot de passe ssid2" value="" name="p2"></p>
               
               <br><button name="save" type="submit" class="button bgrn" type="button" onclick="myFunction()">Enregistrer</button>
            </form>
            <p></p>
            <td style="width:33%"><button onclick="getData();" name="">Scan</button></td>
            <p></p>
         </fieldset>
         <div></div>
         <p></p>
         <form action="./" method="get"><button name="">Retour</button></form>
         <p></p>
         <p></p>
        
         <br>
        
         <div style="text-align:center;font-size:14px;">
            <hr>
            <a target="_blank" style="color:#aaa;"><b>Par Wassim.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Copyrights© 2021 - All Rights Reserved.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Fabriqué Avec <span style="color: #e25555;">&#128274;</span> En Tunisie.</b></a><br>
            
         </div>
      </div>
   </body>
  <script>
function eb(s){return document.getElementById(s);}
function sp(i){eb(i).type=(eb(i).type==='text'?'password':'text');}
function myFunction()
{
  console.log("button was clicked!");
  var ssid = document.getElementById("ssid").value;
  var password = document.getElementById("password").value;
  var ssid2 = document.getElementById("ssid2").value;
  var password2 = document.getElementById("password2").value;
  var data = {ssid:ssid, password:password, ssid2:ssid2, password2:password2};
  var xhr = new XMLHttpRequest();
  var url = "/settings";
  xhr.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      // Typical action to be performed when the document is ready:
      if(xhr.responseText != null){
        console.log(xhr.responseText);
      }
    }
  };
  xhr.open("POST", url, true);
  xhr.send(JSON.stringify(data));
};

  function getData() {
      document.getElementById("ssidscan").innerHTML = "<br>&nbsp;Attendez s'il Vous Plaît !!!<br><br>" ;
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      
      
  document.getElementById("ssidscan").innerHTML = this.responseText ;

    }
  };
  xhttp.open("GET", "wifiscan", true);
  xhttp.send();
}

  function insert(xxx) {
 document.getElementById('ssid').value = xxx ;
}

</script>
</html>
)=====";
