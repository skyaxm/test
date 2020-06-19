#include<libxml/xmlmemory.h>
#include<libxml/parser.h>
#include<libxml/tree.h>
#include<stdio.h>


#if 1
int main(int argc, char* argv[])
{
    xmlDocPtr doc;
    xmlNodePtr curNode;
    char* szDocName="log4crc.xml";

    printf("\n......start......\n");
    doc = xmlReadFile(szDocName, "utf-8", XML_PARSE_RECOVER);
    if(doc==NULL) {
        printf("%s parsed failed\n", szDocName);
        return -1;
    }

    curNode = xmlDocGetRootElement(doc);
    if(curNode==NULL) {
        printf("Empty Document.\n");
        xmlFreeDoc(doc);
        return -1;
    }

    if(xmlStrcmp(curNode->name, (const xmlChar*)"log4c")) {
        printf("root node != log4c\n");
        xmlFreeDoc(doc);
        return -1;
    }

    curNode = curNode->xmlChildrenNode;
    xmlNodePtr propNode = curNode;
    while(curNode != NULL) {
        printf("curNode->name = %s\n", curNode->name);
#if 1
        if(xmlStrcmp(curNode->name, (const xmlChar*)"category")==0) {
            if(xmlHasProp(curNode, BAD_CAST"name")) {
                propNode = curNode;
            }
            xmlAttrPtr attrPtr = propNode->properties;
            while(attrPtr != NULL) {
                if(xmlStrcmp(attrPtr->name, (const xmlChar*)"name")){
                    xmlChar* szPropity = xmlGetProp(propNode, (const xmlChar*)"name");
                    if(xmlStrcmp((const xmlChar*)szPropity, (const xmlChar*)"WLAN_Console")==0) {
                        xmlAttrPtr setAttrPtr = propNode->properties;
                        while(setAttrPtr != NULL) {
                            xmlSetProp(propNode, (const xmlChar*)"priority", (const xmlChar*)"debug");
                            setAttrPtr = setAttrPtr->next;
                        }
                    }
                }
                attrPtr = attrPtr->next;
            }
        }
#endif
        curNode = curNode->next;
    }
    xmlSaveFile("log4crc.xml", doc);
    printf("..........ok.........\n");
}
#endif
