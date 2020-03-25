# Identification materiels

On commence par verifier si la webcam est bien reconnnue : $ lsusb

Ensuite on installe pour verifier les caracteristique de notre camera :

- $ apt-get install v4l-utils v4l-conf
- $ v4l2-ctl --list-devices
- $ v4l-info /dev/video1
- $ v4l-info /dev/video0

On doit ensuite retrouver les formats supportées par la camera :

- $ v4l2-ctl -d /dev/video0 --list-formats
- $ v4l2-ctl -d /dev/video1 --list-formats

# Installation logiciels

On met en place un logiciels de gestion de sources :

- $ sudo apt-get install subversion
- $ mkdir webcams
- $ cd webcams

Ensuite on ajoute MJPG-streamer qui récupère les images JPG des webcams (autre option <https://doc.ubuntu-fr.org/mjpg-streamer>)

- $ svn co <https://mjpg-streamer.svn.sourceforge.net/svnroot/mjpg-streamer> mjpg-streamer

Ensuite on installe les paquets et logiciels pour le traitement d'images

- $ sudo apt-get install libjpeg8-dev
- $ sudo apt-get install imagemagick

Puis on compile

- $ cd mjpg-streamer/mjpg-streamer
- $ make

# Test

On peut lancer le programme (avec notament le format ou le port pour la liaison internet ou autres)

- $ ./mjpg_streamer -i "./input_uvc.so -y -r 320x240" -o "./output_http.so -w ./www"
