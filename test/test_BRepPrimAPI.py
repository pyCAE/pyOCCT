# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC
# Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import unittest

from OCCT.BRepPrimAPI import BRepPrimAPI_MakeBox
from OCCT.TopoDS import TopoDS_Solid, TopoDS_Shell
from OCCT.gp import gp_Pnt


class Test_BRepPrimAPI_MakeBox(unittest.TestCase):
    """
    Test for BRepPrimAPI_MakeBox class.
    """

    @classmethod
    def setUpClass(cls):
        """
        Set up with a BRepPrimAPI_MakeBox.
        """
        p1 = gp_Pnt()
        p2 = gp_Pnt(10, 10, 10)
        cls._builder = BRepPrimAPI_MakeBox(p1, p2)

    def test_Shell(self):
        """
        Test BRepPrimAPI_MakeBox::Shell.
        """
        self.assertIsInstance(self._builder.Shell(), TopoDS_Shell)

    def test_Solid(self):
        """
        Test BRepPrimAPI_MakeBox::Solid.
        """
        self.assertIsInstance(self._builder.Solid(), TopoDS_Solid)


if __name__ == '__main__':
    unittest.main()
