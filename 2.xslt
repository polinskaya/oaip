<?xml version = "1.0" encoding = "UTF-8"?> 
<xsl:stylesheet version = "3.0" 
   xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">    
   <xsl:template match = "/"> 
      <html> 
         <body> 
            <h2>Лабораторная работа 4</h2>
            <table border = "1"> 
               <tr bgcolor = "#9acd32"> 
                  <th>Номер</th> 
                  <th>Имя</th> 
                  <th>Фамилия</th> 
                  <th>Год рождения</th> 
                  <th>Балл</th> 
               </tr> 
			   
               <xsl:for-each select = "class/student"> 
                  <xsl:sort type="number" select = "nickname"/> 
                  <tr> 
                     <td><xsl:value-of select = "@rollno"/></td> 
					  <xsl:choose > 
                           <xsl:when test = "marks = 6"> 
                       <td bgcolor = "green"><xsl:value-of select="firstname"/></td>
                           </xsl:when> 
									
                           <xsl:when test = "6 > marks"> 
                         <td bgcolor = "red"><xsl:value-of select="firstname"/></td>
                           </xsl:when> 
								
                           <xsl:otherwise> 
                             <td><xsl:value-of select="firstname"/></td>
                           </xsl:otherwise> 
                        </xsl:choose>
                     <td><xsl:value-of select = "lastname"/></td> 
                     <td><xsl:value-of select = "nickname"/></td> 
                     <td><xsl:value-of select = "marks"/></td>
					
				  </tr> 
				
               </xsl:for-each> 
            </table>
         </body>
      </html>
   </xsl:template>
</xsl:stylesheet>