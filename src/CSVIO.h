#ifndef CSVIO_H
#define CSVIO_H
#include <ResourceManager.h>

class CSVIO
{
        public:
                void populateResourcesFromList(ResourceManager &rm);
                void createResourcesCSV(const ResourceManager &rm);

        private:
};

#endif
