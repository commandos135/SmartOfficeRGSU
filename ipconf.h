char ipconf[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="fr" class="">
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
      <meta name="viewport" content="width=device-width,initial-scale=1,user-scalable=no">
      <title>Configuration Adresse IP</title>
      <style>div,fieldset,input,select{padding:5px;font-size:1em;}fieldset{background:#4f4f4f;}p{margin:0.5em 0;}input{width:100%;box-sizing:border-box;-webkit-box-sizing:border-box;-moz-box-sizing:border-box;background:#dddddd;color:#000000;}input[type=checkbox],input[type=radio]{width:1em;margin-right:6px;vertical-align:-1px;}input[type=range]{width:99%;}select{width:100%;background:#dddddd;color:#000000;}textarea{resize:vertical;width:98%;height:318px;padding:5px;overflow:auto;background:#1f1f1f;color:#65c115;}body{text-align:center;font-family:verdana,sans-serif;background:#252525;}td{padding:0px;}button{border:0;border-radius:0.3rem;background:#1fa3ec;color:#faffff;line-height:2.4rem;font-size:1.2rem;width:100%;-webkit-transition-duration:0.4s;transition-duration:0.4s;cursor:pointer;}button:hover{background:#0e70a4;}.bred{background:#d43535;}.bred:hover{background:#931f1f;}.bgrn{background:#47c266;}.bgrn:hover{background:#5aaf6f;}a{color:#1fa3ec;text-decoration:none;}.p{float:left;text-align:left;}.q{float:right;text-align:right;}.r{border-radius:0.3em;padding:2px;margin:6px 2px;}</style>
   </head>
   <body>
      <div style="text-align:left;display:inline-block;color:#eaeaea;min-width:340px;">
         <div style="text-align:center;color:#eaeaea;">
            <noscript>Pour utiliser , veuillez activer JavaScript<br></noscript>
 
            <h2>Configuration Adresse IP</h2><br>
         </div>
         <fieldset>
            <legend><b>&nbsp;Paramètres Adresse IP&nbsp;</b></legend>
            <form>
               <p><b>Adresse IP</b> <br><input id="ip" placeholder="192.168.1.100" value="" ></p>
               <p><b>Masque sous-réseau</b> <br><input id="masque" placeholder="255.255.255.0" value="" ></p>
               <p><b>Passerelle</b><br><input id="passrelle" placeholder="192.168.1.1" value="" ></p>
               <p><b>Dns</b><br><input id="dns" placeholder="8.8.8.8" value="" ></p>

               <br><button type="submit" class="button bgrn" onclick="myFunction()" >Enregistrer</button>
            </form>
         </fieldset>
         <div></div>
         <p></p>
         <form action="./" method="get"><button name="">Retour</button></form>
         <p></p>
         <div style="text-align:center;font-size:14px;">
            <hr>
            <a target="_blank" style="color:#aaa;"><b>Par wassim.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Copyrights© 2021 - All Rights Reserved.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Fabriqué Avec <span style="color: #e25555;">&#128275;</span> En Tunisie.</b></a><br>
            
         </div>
      </div>
   </body>
    <script>
function myFunction()
{
 // console.log("button was clicked!");
  var ip = document.getElementById("ip").value;
  var masque = document.getElementById("masque").value;
  var passrelle = document.getElementById("passrelle").value;
  var dns = document.getElementById("dns").value;

  var ipformat = /^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/;
 if(ip.match(ipformat) && masque.match(ipformat) && passrelle.match(ipformat) && dns.match(ipformat))
 {

  var data = {ip:ip, masque:masque, passrelle:passrelle, dns:dns };
  var xhr = new XMLHttpRequest();
  var url = "/settings3";
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
   }
   else
 {
 alert("You have entered an invalid Data !");
 }
  
};

</script>
</html>
)=====";
