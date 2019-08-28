echo "Move from Downloads to Down container in order to save C disk storage"
echo "List all file in Downloads directory"
cd /media/dinhthong/SYSTEM/Users/nguye/Downloads
ls
echo "Move all files in this directory"
mv * /media/dinhthong/CERBER/Down_container
cd Compressed
mv * /media/dinhthong/CERBER/Down_container/Compressed
cd ..
cd Documents
mv * /media/dinhthong/CERBER/Down_container/Documents
cd ..
cd Programs
mv * /media/dinhthong/CERBER/Down_container/Programs
cd ..
cd Video
mv * /media/dinhthong/CERBER/Down_container/Video

