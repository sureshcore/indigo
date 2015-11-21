#ifndef INDIGO_PASS_H
#define INDIGO_PASS_H

namespace Indigo
{

    class Pass
    {
        int i;

    public:
        Pass();
        virtual ~Pass();

        virtual void run() {}
    };

}

#endif // INDIGO_PASS_H
