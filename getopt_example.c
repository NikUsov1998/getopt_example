#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <sys/syslog.h>
#include <syslog.h>

#define DEBUG

int main (int argc, char *argv[]){

  openlog("logs_opts_example", LOG_PID, LOG_USER);
#ifdef DEBUG
  syslog(LOG_INFO, "[INFO]\tStart example");
#endif
	const char* short_options = "hsv::f:";

	const struct option long_options[] = {
    { "help", optional_argument, NULL, 'h' },
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
#ifdef DEBUG
  syslog(LOG_DEBUG, "[INFO]\tPrint help");
#endif
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
				printf("option_index = %d (\"%s\",%d,%c)\n",
					option_index,
					long_options[option_index].name,
					long_options[option_index].has_arg,
					long_options[option_index].val
				);
				if (optarg!=NULL)
					printf("found size with value %s\n",optarg);
				else
					printf("found size without value\n");
				break;
			};
	
			case 'f': {
				printf("option_index = %d (\"%s\",%d,%c)\n",
					option_index,
					long_options[option_index].name,
					long_options[option_index].has_arg,
					long_options[option_index].val
				);
				printf("file = %s\n",optarg);
				break;
			};

      case 'v': {
				printf("option_index = %d (\"%s\",%d,%c)\n",
					option_index,
					long_options[option_index].name,
					long_options[option_index].has_arg,
					long_options[option_index].val
				);
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
  openlog("test_stderr", LOG_PERROR | LOG_PID, LOG_USER);
  syslog(LOG_PERROR, "[ERROR]\tTEST ERROR");
  closelog();
	return 0;
};
