<!DOCTYPE html>
<html>
  <head>
    <title>stats</title>
  </head>


  <body>

    <h1>Stats of 10 numbers</h1>
    <p>Enter 10 numbers within 1 and 100 for a statistical analysis.</p>

    <?php
       // define variables and set to empty values
       $arg1 = $arg2 = $output = $retc = "";

       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         $arg2 = test_input($_POST["arg2"]);
	 $arg3 = test_input($_POST["arg3"]);
         $arg4 = test_input($_POST["arg4"]);
         $arg5 = test_input($_POST["arg5"]);
         $arg6 = test_input($_POST["arg6"]);
         $arg7 = test_input($_POST["arg7"]);
         $arg8 = test_input($_POST["arg8"]);
         $arg9 = test_input($_POST["arg9"]);
         $arg0 = test_input($_POST["arg0"]);
         exec("/usr/lib/cgi-bin/sp1b/stats" . $arg1 . " " . $arg2 . " " . $arg3 . " " . $arg4 . " " . $arg5 . " " . $arg6 . " " . $arg7 . " " . $arg8 . " " . $arg9 . " " . $arg0, $output, $retc); 
       }

       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Arg1: <input type="text" name="arg1"><br>
      Arg2: <input type="text" name="arg2"><br>
      Arg3: <input type="text" name="arg3"><br>
      Arg4: <input type="text" name="arg4"><br>
      Arg5: <input type="text" name="arg5"><br>
      Arg6: <input type="text" name="arg6"><br>
      Arg7: <input type="text" name="arg7"><br>
      Arg8: <input type="text" name="arg8"><br>
      Arg9: <input type="text" name="arg9"><br>
      Arg0: <input type="text" name="arg0"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
       // only display if return code is numeric - i.e. exec has been called
       if (is_numeric($retc)) {
         echo "<h2>Your Input:</h2>";
         echo $arg1;
         echo "<br>";
         echo $arg2;
         echo "<br>";
         echo $arg3;
         echo "<br>";
         echo $arg4;
         echo "<br>";
         echo $arg5;
         echo "<br>";
         echo $arg6;
         echo "<br>";
         echo $arg7;
         echo "<br>";
         echo $arg8;
         echo "<br>";
         echo $arg9;
         echo "<br>";
         echo $arg0;
         echo "<br>";
       
         echo "<h2>Program Output (an array):</h2>";
         foreach ($output as $line) {
           echo $line;
           echo "<br>";
         }
       
         echo "<h2>Program Return Code:</h2>";
         echo $retc;
       }
    ?>
    
  </body>
</html>
