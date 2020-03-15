/******************************************************************
 * Copyright(C) 2020-2020. All right reserved.
 *
 * Filename: main.go
 * Author: ahaoozhang
 * Date: 2020-03-15 21:34:35 (Sunday)
 * Describe:
 ******************************************************************/

package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()
	r.GET("/", func(c *gin.Context) {
		c.SetCookie("test_cookie", "test value", 10, "/", "", false, true)
		c.JSON(http.StatusOK, gin.H{
			"cookie": "ok",
		})
	})
	r.GET("/cookie", func(c *gin.Context) {
		cookie, _ := c.Request.Cookie("test_cookie")
		c.JSON(http.StatusOK, gin.H{
			"cookie": cookie.String(),
		})
	})

	r.Run(":8000")
}
