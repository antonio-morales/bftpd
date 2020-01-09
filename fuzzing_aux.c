int readFile(const char *filePath, uint8_t **buffer){

	FILE * pFile;
	  long lSize;
	  size_t result;

	  pFile = fopen ( filePath , "rb" );
	  if (pFile==NULL) {exit (1);}

	  // obtain file size:
	  fseek (pFile , 0 , SEEK_END);
	  lSize = ftell (pFile);
	  rewind (pFile);

	  // allocate memory to contain the whole file:
	  *buffer = (uint8_t *) malloc (sizeof(uint8_t )*lSize);
	  if (buffer == NULL) {exit (2);}

	  // copy the file into the buffer:
	  result = fread (*buffer,1,lSize,pFile);
	  if (result != lSize) {exit (3);}

	  /* the whole file is now loaded in the memory buffer. */

	  // terminate
	  fclose (pFile);

	  return lSize;

}

