# gets the ubuntu latest thing
FROM ubuntu:latest

# installs dependencies
RUN apt-get update && apt-get install -y clang make rustc curl
#installs the essental collection 
RUN curl -t https://neopack.nain.xyz/essential/essential.sh | bash
#runs tests
RUN clang test/test.c && ./a.out
