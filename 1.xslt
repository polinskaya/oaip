<?xml version="1.0" encoding="ISO-8859-1"?> 
<xsl:stylesheet version="3.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>	
<body>
<h2>Лабораторная работа 3</h2>
  <table border="2">
  <tbody>
  <tr>
  <th style="text-align:center">Университет</th>
  <th style="text-align:center">Проходной балл</th>
  <th style="text-align:center">План набора</th>
  <th style="text-align:center">Город</th>
  </tr>
  <xsl:for-each select="Specialization/University" >
	<tr> 
     <th><xsl:value-of select="Name"/></th>
     <th><xsl:value-of select="Mark"/></th>
     <th><xsl:value-of select="Students"/></th>
    <th><xsl:value-of select="City"/></th>
  </tr>
  </xsl:for-each>
	</tbody>
 </table>
</body>
</html>
</xsl:template>

</xsl:stylesheet>