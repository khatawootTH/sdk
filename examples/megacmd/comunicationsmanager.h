/**
 * @file examples/megacmd/comunicationsmanager.h
 * @brief MegaCMD: Communications manager
 *
 * (c) 2013-2016 by Mega Limited, Auckland, New Zealand
 *
 * This file is part of the MEGA SDK - Client Access Engine.
 *
 * Applications using the MEGA API must present a valid application key
 * and comply with the the rules set forth in the Terms of Service.
 *
 * The MEGA SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * @copyright Simplified (2-clause) BSD License.
 *
 * You should have received a copy of the license along with this
 * program.
 */

#ifndef COMUNICATIONSMANAGER_H
#define COMUNICATIONSMANAGER_H

#include "megacmd.h"

using namespace mega;

class CmdPetition
{
    public:
        char * line = NULL;

        char *getLine()
        {
            return line;
        }
        ~CmdPetition()
        {
            if ( line != NULL )
            {
                free(line);
            }
        }
};


std::ostream &operator<<(std::ostream &os, CmdPetition const &p);

class ComunicationsManager
{
private:
    fd_set fds;

public:
    ComunicationsManager();

    virtual bool receivedReadlineInput(int readline_fd);

    virtual bool receivedPetition();

    virtual int waitForPetitionOrReadlineInput(int readline_fd);
    virtual int waitForPetition();

    /**
     * @brief returnAndClosePetition
     * I will clean struct and close the socket within
     */
    virtual void returnAndClosePetition(CmdPetition *inf, std::ostringstream *s, int);

    /**
     * @brief getPetition
     * @return pointer to new CmdPetition. Petition returned must be properly deleted (this can be calling returnAndClosePetition)
     */
    virtual CmdPetition *getPetition();

    /**
     * @brief get_petition_details
     * @return a string describing details of the petition
     */
    virtual string get_petition_details(CmdPetition *inf);

    ~ComunicationsManager();
};

#endif // COMUNICATIONSMANAGER_H
