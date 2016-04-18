
#!/bin/bash
device=/dev/minicut_virtmnc;
#rmmod parrot_driver;
#compilation!!!./fini.sh;
#insmod parrot_driver.ko;
#si fichier normal on l'efface
if [  -f $device ]; then
    rm device;
fi
    insmod parrot_driver.ko
#if pas de fichier/device, on tue!
if [ ! -e $device ]; then
    echo  "test.sh unable to load driver";
    exit -1;
fi


#echo "VIRTUAL PARROT DRIVER TEST!\n";

echo "echo '1st test' then '2nd test' in $device";

echo '1er test'> $device;
echo '2eme test'> $device;

#echo "envoie de 3eme MSG dans le driver\n";
#echo '3eme MSG'> $device;

echo "FIRST IN:$device must return '1st test' then '2nd test'";
cat $device;
#echo "SECOND IN:doit afficher :'deuxieme test'";
cat $device;
#echo "doit afficher :3eme MSG";
#cat $device;
exit 0;
