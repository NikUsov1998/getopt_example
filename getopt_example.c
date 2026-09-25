
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "hsv::f:";

	const struct option long_options[] = {
    { "help", no_argument, NULL, 'h' },
    { "size", optional_argument, NULL, 's' },
    { "visual", optional_argument, NULL, 'v'},
    { "file", required_argument, NULL, 'f' },
    { NULL, 0, NULL, 0 }
	};

	int rez;
	int option_index = -1;

	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(rez){
			case 'h': {
				printf("This is demo help. Try -h or --help.\n");
				printf("option_index = %d (\"%s\",%d,%c)\n",
					option_index,
					long_options[option_index].name,
					long_options[option_index].has_arg,
					long_options[option_index].val
				);
				break;
			};

			case 's': {
				if (optarg!=NULL)
					printf("found size with value %s\n",optarg);
				else
					printf("found size without value\n");
				break;
			};
	
			case 'f': {
				printf("file = %s\n",optarg);
				break;
			};

      case 'v': {
        printf("DEBUG INFO:\t%s\n", optarg);
        break;
      };

			case '?': default: {
				printf("found unknown option\n");
				break;
			};
		};
    option_index = -1;
	};
	return 0;
};
