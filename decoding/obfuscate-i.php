<?php
date_default_timezone_set('UTC');

  function parseArgs($argv){

         array_shift($argv);
         $out                            = array();

         foreach ($argv as $arg){

             // --foo --bar=baz
             if (substr($arg,0,2) == '--'){
                 $eqPos                  = strpos($arg,'=');

                 // --foo
                 if ($eqPos === false){
                     $key                = substr($arg,2);
                     $value              = isset($out[$key]) ? $out[$key] : true;
                     $out[$key]          = $value;
                 }
                 // --bar=baz
                 else {
                     $key                = substr($arg,2,$eqPos-2);
                     $value              = substr($arg,$eqPos+1);
                     $out[$key]          = $value;
                 }
             }
             // -k=value -abc
             else if (substr($arg,0,1) == '-'){

                 // -k=value
                 if (substr($arg,2,1) == '='){
                     $key                = substr($arg,1,1);
                     $value              = substr($arg,3);
                     $out[$key]          = $value;
                 }
                 // -abc
                 else {
                     $chars              = str_split(substr($arg,1));
                     foreach ($chars as $char){
                         $key            = $char;
                         $value          = isset($out[$key]) ? $out[$key] : true;
                         $out[$key]      = $value;
                     }
                 }
             }
             // plain-arg
             else {
                 $value                  = $arg;
                 $out[]                  = $value;
             }
         }
         return $out;
     }
$args = parseArgs($argv);

echo "Obfuscating strings in ".$args[1]."\r\n";

$f = fopen($args[0], 'rb');
$o = fopen($args[1], 'wb');

define('ENCODESTRTOKEN', 'OBPREPROCESSENCODEDSTR(');

while ($line= fgets ($f)) 
{
	while (($esp = strpos($line, ENCODESTRTOKEN))!==false)
	{
		$sesp = $esp;
		$esp+=strlen(ENCODESTRTOKEN);
		while ($line[$esp]!='"') $esp++;
		$esp++;
		$sstart = $esp;
		$s = '';
		while (true)
		{
			if ($line[$esp]=='"') break;
			if ($esp>=strlen($line)) break;
			if ($line[$esp]=='\\')
			{
				if ($line[$esp+1]=='\\') $s.='\\';
				if ($line[$esp+1]=='r') $s.="\r";
				if ($line[$esp+1]=='n') $s.="\n";
				if ($line[$esp+1]=='t') $s.="\t";
				$esp+=2;
				continue;
			}
			$s.=$line[$esp];
			$esp++;
		}
		
		$enc = "";
		
		$ch = 0;
		$chphase = 0;
		while ($ch<strlen($s))
		{
			if ($chphase==0) 
				$cod = ord($s[$ch]) & 15;
			else
				$cod = (ord($s[$ch]) & (255-15))/16;
			$cod = dechex(rand(1,15)*16 + $cod);
			
			$enc.="\\x$cod";
			
			if ($chphase==0) $chphase = 1; 
				else 
			{ $ch++; $chphase = 0;};
		}
		
		echo "Obfuscating string \"$s\" to \"$enc\"\r\n";
		$line = substr_replace($line, $enc, $sstart, $esp-$sstart);
		$line = substr_replace($line, "", $sesp, strlen(ENCODESTRTOKEN)-1);
	};
	fputs($o, $line);
};

?>