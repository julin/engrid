// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +                                                                      +
// + This file is part of enGrid.                                         +
// +                                                                      +
// + Copyright 2008-2014 enGits GmbH                                      +
// +                                                                      +
// + enGrid is free software: you can redistribute it and/or modify       +
// + it under the terms of the GNU General Public License as published by +
// + the Free Software Foundation, either version 3 of the License, or    +
// + (at your option) any later version.                                  +
// +                                                                      +
// + enGrid is distributed in the hope that it will be useful,            +
// + but WITHOUT ANY WARRANTY; without even the implied warranty of       +
// + MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        +
// + GNU General Public License for more details.                         +
// +                                                                      +
// + You should have received a copy of the GNU General Public License    +
// + along with enGrid. If not, see <http://www.gnu.org/licenses/>.       +
// +                                                                      +
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef SOLVEROBJECT_H
#define SOLVEROBJECT_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>

#include "engrid.h"


class SolverObject
{

private: // attributes

  QString      m_CaseDir;
  QVector<int> m_VolToSurfMap;
  QVector<int> m_SurfToVolMap;
  int          m_FirstBoundaryFace;
  QByteArray   m_Buffer;
  QString      m_BufferedFileName;
  QString      m_SolverVersion;


private: // methods

  int  deleteBetween(int i, QString str1, QString str2);
  void stripBuffer();


protected: // methods

  void readFile(QString file_name);
  QByteArray* getBuffer() { return &m_Buffer; }
  void buildFoamMaps();
  int numVolNodes() { return m_VolToSurfMap.size(); }
  int numSurfNodes() { return m_SurfToVolMap.size(); }
  int surfToVol(int i) { return m_SurfToVolMap[i]; }
  int volToSurf(int i) { return m_VolToSurfMap[i]; }
  int getFirstBoundaryFace() { return m_FirstBoundaryFace; }
  void writeSolverParameters(QString case_dir);


public:

  SolverObject();

  void setCaseDir (QString case_dir);
  void setSolverVersion(QString version) { m_SolverVersion = version; }
  QString getSolverVersion() { return m_SolverVersion; }

};

#endif // SOLVEROBJECT_H
