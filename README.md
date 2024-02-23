# Star-Rail-MusicPkgDecryptor
## What is it used for
　To unpack the musicxx.pck.Because the file header is "traditional", the decryption is easy
## API
　int FireReborn::Unpack(const char *FileInDir, const char *FileOutDir, int Flag);  
  
　You should provide the music.pck's path.Then you can get .wem files.They will be stored in dir:${FileOutDir}/OutPut/Music  
  
　The "Flag" parameter is in reserve.
###  But!!! 
　At this moment,general audio player can't play .wem file.You should transfer its format to.ogg or other formats which can be played by player.  
  
　There is a git that can complete it:  
　-[RadicalMusic-Decryptor](https://github.com/CrunchyRLL/RadicalMusic-Decryptor).  
## Thoughts
　I love firefly.If SHAOJI let firefly die, I will let him CHI BU LIAO DOU ZHE ZOU.  
  
　In fact, many similar programs already exist.I don't have to finish it.But the scene gets me down.So I don't have little mood to do other things.

　Do this to comfort myself.
