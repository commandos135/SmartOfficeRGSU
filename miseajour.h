const char miseajour[] PROGMEM = R"=====(
<!DOCTYPE html>

<html lang="fr" class="">
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
      <meta name="viewport" content="width=device-width,initial-scale=1,user-scalable=no">
      <title>Mise à jour du Firmware</title>
      <style>div,fieldset,input,select{padding:5px;font-size:1em;}fieldset{background:#4f4f4f;}p{margin:0.5em 0;}input{width:100%;box-sizing:border-box;-webkit-box-sizing:border-box;-moz-box-sizing:border-box;background:#dddddd;color:#000000;}input[type=checkbox],input[type=radio]{width:1em;margin-right:6px;vertical-align:-1px;}input[type=range]{width:99%;}select{width:100%;background:#dddddd;color:#000000;}textarea{resize:vertical;width:98%;height:318px;padding:5px;overflow:auto;background:#1f1f1f;color:#65c115;}body{text-align:center;font-family:verdana,sans-serif;background:#252525;}td{padding:0px;}button{border:0;border-radius:0.3rem;background:#1fa3ec;color:#faffff;line-height:2.4rem;font-size:1.2rem;width:100%;-webkit-transition-duration:0.4s;transition-duration:0.4s;cursor:pointer;}button:hover{background:#0e70a4;}.bred{background:#d43535;}.bred:hover{background:#931f1f;}.bgrn{background:#47c266;}.bgrn:hover{background:#5aaf6f;}a{color:#1fa3ec;text-decoration:none;}.p{float:left;text-align:left;}.q{float:right;text-align:right;}.r{border-radius:0.3em;padding:2px;margin:6px 2px;}.si{display:inline-flex;align-items:flex-end;height:15px;padding:0}.si i{width:3px;margin-right:1px;border-radius:3px;background-color:#eaeaea}.si .b0{height:25%}.si .b1{height:50%}.si .b2{height:75%}.si .b3{height:100%}.o30{opacity:.3}</style>
   </head>
   <body>
      <div style="text-align:left;display:inline-block;color:#eaeaea;min-width:340px;">
         <div style="text-align:center;color:#eaeaea;">
            <noscript>Pour utiliser , veuillez activer JavaScript<br></noscript>
                      <h2>Mise à jour du Firmware</h2><br>
         </div>
         <br>
         <fieldset>
            <legend><b>&nbsp;Mise à jour &nbsp;</b></legend>
           <div> <br><b style="text-align:left;font-size:20px;">NB:</b><b style="text-align:left;font-size:16px;"> La carte peut être détruite <br> en cas de mise à jour non officielle.</b><br><br></div>
         <form method='POST' action='/update' onsubmit="return confirm(&quot;Confirmer la Mise à jour du Firmware.&quot;);" enctype='multipart/form-data'><br>
         <input type='file' name='update'><br><br>
         <button type="submit" name=""  >Lancer la mise à jour</button>
         </form>
         </fieldset>
         <div></div>
         <p></p>
         <form action="./" method="get"><button name="">Retour</button></form>
         <p></p>
         <p></p>
        
         <br>
        
         <div style="text-align:center;font-size:14px;">
            <hr>
            <a target="_blank" style="color:#aaa;"><b>Par SeifEddine Achour Et Najeh Fatthallah.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Copyrights© 2021 - All Rights Reserved.</b></a><br>
            <a target="_blank" style="color:#aaa;"><b>Fabriqué Avec <span style="color: #e25555;">&#10084;</span> En Tunisie.</b></a><br>
            
         </div>
      </div>
   </body>
</html>
)=====";
