//*****************************************************************
/*
  JackTrip: A System for High-Quality Audio Network Performance
  over the Internet

  Copyright (c) 2008 Juan-Pablo Caceres, Chris Chafe.
  SoundWIRE group at CCRMA, Stanford University.

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this software and associated documentation
  files (the "Software"), to deal in the Software without
  restriction, including without limitation the rights to use,
  copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following
  conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.
*/
//*****************************************************************

/**
 * \file Patcher.h
 * \author Aaron Wyatt
 * \date September 2020
 */
 
#ifndef __PATCHER_H__
#define __PATCHER_H__
 
#include <jack/jack.h>
#include <iostream>
#include <QStringList>
#include <QMutex>
#include <QObject>
#include <QDebug>

class Patcher: public QObject
{
    Q_OBJECT
    
public:
    Patcher();
    virtual ~Patcher();
    
    void registerClient(const QString &clientName);
    void unregisterClient(const QString &clientName);
    
private:
    QStringList m_clients;
    
    jack_client_t *m_jackClient;
    jack_status_t m_status;
    static void s_cp_patch(jack_port_id_t port, int reg, void * p);
    void cp_patch(jack_port_id_t port, int reg);

    QMutex m_connectionMutex;

signals:
    void newPort();
private slots:
    void doNewPort();
};
 
#endif // __PATCHER_H__
 
