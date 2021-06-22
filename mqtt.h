char mqtt[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="fr" class="">
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
      <meta name="viewport" content="width=device-width,initial-scale=1,user-scalable=no">
      <title>Configuration MQTT</title>
      <style>div,fieldset,input,select{padding:5px;font-size:1em;}fieldset{background:#4f4f4f;}p{margin:0.5em 0;}input{width:100%;box-sizing:border-box;-webkit-box-sizing:border-box;-moz-box-sizing:border-box;background:#dddddd;color:#000000;}input[type=checkbox],input[type=radio]{width:1em;margin-right:6px;vertical-align:-1px;}input[type=range]{width:99%;}select{width:100%;background:#dddddd;color:#000000;}textarea{resize:vertical;width:98%;height:318px;padding:5px;overflow:auto;background:#1f1f1f;color:#65c115;}body{text-align:center;font-family:verdana,sans-serif;background:#252525;}td{padding:0px;}button{border:0;border-radius:0.3rem;background:#1fa3ec;color:#faffff;line-height:2.4rem;font-size:1.2rem;width:100%;-webkit-transition-duration:0.4s;transition-duration:0.4s;cursor:pointer;}button:hover{background:#0e70a4;}.bred{background:#d43535;}.bred:hover{background:#931f1f;}.bgrn{background:#47c266;}.bgrn:hover{background:#5aaf6f;}a{color:#1fa3ec;text-decoration:none;}.p{float:left;text-align:left;}.q{float:right;text-align:right;}.r{border-radius:0.3em;padding:2px;margin:6px 2px;}</style>
   </head>
   <body>
      <div style="text-align:left;display:inline-block;color:#eaeaea;min-width:340px;">
         <div style="text-align:center;color:#eaeaea;">
            <noscript>Pour utiliser , veuillez activer JavaScript<br></noscript>
 
            <h2>Configuration MQTT</h2><br>
         </div>
         <fieldset>
            <legend><b>&nbsp;Paramètres MQTT&nbsp;</b></legend>
            <form>
               <p><b>Hôte</b> <br><input id="hote" placeholder="127.0.0.1" value="" name="mh"></p>
               <p><b>Port</b> <br><input id="port" placeholder="1883" value="" name="ml"></p>
               <p><b>Utilisateur</b><br><input id="user" placeholder="DVES_USER" value="" name="mu"></p>
               <p><label><b>Mot de passe</b><input type="checkbox" onclick="sp(&quot;passwordm&quot;)" name=""></label><br>
               <input id="passwordm" type="password" placeholder="Mot de passe" value="" name="mp"></p>
               <p><b>Topic</b><br><input id="topic" placeholder="home/room1" value="" name="mt"></p>

               <br><button name="save" type="submit" class="button bgrn" onclick="myFunction()" >Enregistrer</button>
            </form>
         </fieldset>
         <div></div>
         <p></p>
         <form action="./" method="get"><button name="">Retour</button></form>
         <p></p>
         <div style="text-align:center;font-size:14px;">
            <hr>
            <a target="_blank" style="color:#aaa;"><b>Par SeifEddine Achour Et Najeh Fatthallah.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Copyrights© 2021 - All Rights Reserved.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Fabriqué Avec <span style="color: #e25555;">&#128275;</span> En Tunisie.</b></a><br>
            
         </div>
      </div>
   </body>
    <script>
function eb(s){return document.getElementById(s);}
function sp(i){eb(i).type=(eb(i).type==='text'?'password':'text');}
function myFunction()
{
  console.log("button was clicked!");
  var hote = document.getElementById("hote").value;
  var port = document.getElementById("port").value;
  var user = document.getElementById("user").value;
  var passwordm = document.getElementById("passwordm").value;
  var topic = document.getElementById("topic").value;
  var data = {hote:hote, port:port, user:user, passwordm:passwordm, topic:topic};
  var xhr = new XMLHttpRequest();
  var url = "/settings2";
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
</script>
</html>
)=====";
