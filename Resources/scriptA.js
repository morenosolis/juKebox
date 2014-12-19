var InputPath = {value : "/home/carlos/M\u00fasica"};
String.prototype.replaceAt=function(index, character) {
    console.log("Replace: "+index+" - "+character);
    return this.substr(0, index) + character + this.substr(index+character.length);
}

Number.prototype.padLeft = function (n,str){
    return Array(n-String(this).length+1).join(str||'0')+this;
}

try{

    WindowObj.SearchMusic(InputPath.value);
    Catalog =  JSON.parse(WindowObj.GetCatalog());
}catch(Exception){
    WindowObj = {
        GetCatalog : function() {
            return {
                "Albums": [
                    {
                        "Artist": "Metallica",
                        "Title": "The Greatest Hits CD1",
                        "Tracks": [
                            {
                                "Artist": "",
                                "Title": "One",
                                "TrackNumber": 1
                            },
                            {
                                "Artist": "",
                                "Title": "Enter Sandman",
                                "TrackNumber": 2
                            },
                            {
                                "Artist": "",
                                "Title": "Master Of Puppets",
                                "TrackNumber": 3
                            },
                            {
                                "Artist": "",
                                "Title": "Fade To Black",
                                "TrackNumber": 4
                            },
                            {
                                "Artist": "",
                                "Title": "The Unforgiven",
                                "TrackNumber": 5
                            },
                            {
                                "Artist": "",
                                "Title": "The Small Hours",
                                "TrackNumber": 6
                            },
                            {
                                "Artist": "",
                                "Title": "Seek & Destroy",
                                "TrackNumber": 7
                            },
                            {
                                "Artist": "",
                                "Title": "Whiplash",
                                "TrackNumber": 8
                            },
                            {
                                "Artist": "",
                                "Title": "Last Caress-Green Hell",
                                "TrackNumber": 9
                            },
                            {
                                "Artist": "",
                                "Title": "Sad But True",
                                "TrackNumber": 10
                            },
                            {
                                "Artist": "",
                                "Title": "Welcome Home (Sanitarium)",
                                "TrackNumber": 12
                            },
                            {
                                "Artist": "",
                                "Title": "Metal Militia",
                                "TrackNumber": 13
                            }
                        ]
                    },
                    {
                        "Artist": "Metallica",
                        "Title": "The Greatest Hits CD2",
                        "Tracks": [
                            {
                                "Artist": "",
                                "Title": "Fuel",
                                "TrackNumber": 1
                            },
                            {
                                "Artist": "",
                                "Title": "Broken, Beat & Scarred",
                                "TrackNumber": 2
                            },
                            {
                                "Artist": "",
                                "Title": "Wherever I May Roam",
                                "TrackNumber": 3
                            },
                            {
                                "Artist": "",
                                "Title": "Nothing Else Matters",
                                "TrackNumber": 4
                            },
                            {
                                "Artist": "",
                                "Title": "Blackened",
                                "TrackNumber": 5
                            },
                            {
                                "Artist": "",
                                "Title": "The Shortest Straw",
                                "TrackNumber": 6
                            },
                            {
                                "Artist": "",
                                "Title": "For Whom The Bell Tolls",
                                "TrackNumber": 8
                            },
                            {
                                "Artist": "",
                                "Title": "Creeping Death",
                                "TrackNumber": 9
                            },
                            {
                                "Artist": "",
                                "Title": "Trapped Under Ice",
                                "TrackNumber": 10
                            },
                            {
                                "Artist": "",
                                "Title": "The Thing That Should Not Be",
                                "TrackNumber": 11
                            },
                            {
                                "Artist": "",
                                "Title": "(Anesthesia)-Pulling Teeth",
                                "TrackNumber": 12
                            },
                            {
                                "Artist": "",
                                "Title": "Orion (Instramental)",
                                "TrackNumber": 13
                            }
                        ]
                    },
                    {
                        "Artist": "Pink Floyd",
                        "Title": "Wish You Were Here  2011",
                        "Tracks": [
                            {
                                "Artist": "",
                                "Title": "Shine On You Crazy Diamond, [Part One]",
                                "TrackNumber": 1
                            },
                            {
                                "Artist": "",
                                "Title": "Welcome To The Machine",
                                "TrackNumber": 2
                            },
                            {
                                "Artist": "",
                                "Title": "Have A Cigar",
                                "TrackNumber": 3
                            },
                            {
                                "Artist": "",
                                "Title": "Shine On You Crazy Diamond, [Part Two]",
                                "TrackNumber": 5
                            }
                        ]
                    },
                    {
                        "Artist": "Varios Artistas",
                        "Title": "Calamaro Querido - Cantando Al Salmón (2006) CD 1",
                        "Tracks": [
                            {
                                "Artist": "",
                                "Title": "Los Fabulosos Cadillacs",
                                "TrackNumber": 1
                            },
                            {
                                "Artist": "",
                                "Title": "Fabiana Cantilo",
                                "TrackNumber": 3
                            },
                            {
                                "Artist": "",
                                "Title": "Arbol",
                                "TrackNumber": 4
                            },
                            {
                                "Artist": "",
                                "Title": "Fito Paez",
                                "TrackNumber": 5
                            },
                            {
                                "Artist": "",
                                "Title": "Bahiano",
                                "TrackNumber": 6
                            },
                            {
                                "Artist": "",
                                "Title": "Kevin Johansen",
                                "TrackNumber": 7
                            },
                            {
                                "Artist": "",
                                "Title": "Muchachito Bombo Infierno",
                                "TrackNumber": 8
                            },
                            {
                                "Artist": "",
                                "Title": "Diego Torres",
                                "TrackNumber": 9
                            },
                            {
                                "Artist": "",
                                "Title": "Pereza",
                                "TrackNumber": 10
                            },
                            {
                                "Artist": "",
                                "Title": "Los tipitos",
                                "TrackNumber": 11
                            },
                            {
                                "Artist": "",
                                "Title": "Iván Noble",
                                "TrackNumber": 12
                            }
                        ]
                    },
                    {
                        "Artist": "Varios Artistas",
                        "Title": "Calamaro Querido - Cantando Al Salmón (2006) CD 2",
                        "Tracks": [
                            {
                                "Artist": "",
                                "Title": "Julieta Venegas",
                                "TrackNumber": 1
                            },
                            {
                                "Artist": "",
                                "Title": "Joaquin Sabina",
                                "TrackNumber": 2
                            },
                            {
                                "Artist": "",
                                "Title": "Los Pericos",
                                "TrackNumber": 3
                            },
                            {
                                "Artist": "",
                                "Title": "Niña Pastor",
                                "TrackNumber": 5
                            },
                            {
                                "Artist": "",
                                "Title": "Vicentico",
                                "TrackNumber": 6
                            },
                            {
                                "Artist": "",
                                "Title": "Soledad",
                                "TrackNumber": 7
                            },
                            {
                                "Artist": "",
                                "Title": "Mancha de Rolando",
                                "TrackNumber": 8
                            },
                            {
                                "Artist": "",
                                "Title": "Los autenticos decadentes",
                                "TrackNumber": 9
                            },
                            {
                                "Artist": "",
                                "Title": "Pedro aznar",
                                "TrackNumber": 10
                            },
                            {
                                "Artist": "",
                                "Title": "Javier Calamaro",
                                "TrackNumber": 11
                            },
                            {
                                "Artist": "",
                                "Title": "Tabaquito Marroquí",
                                "TrackNumber": 12
                            },
                            {
                                "Artist": "",
                                "Title": "Litto Nebbia",
                                "TrackNumber": 13
                            }
                        ]
                    },
                    {
                        "Artist": "Varios Artistas",
                        "Title": "La Habana Canta a Sabina",
                        "Tracks": [
                            {
                                "Artist": "",
                                "Title": "Una Cancion Para La Magdalena",
                                "TrackNumber": 1
                            },
                            {
                                "Artist": "",
                                "Title": "Quien Me Ha Robado El Mes De Abril",
                                "TrackNumber": 2
                            },
                            {
                                "Artist": "",
                                "Title": "Que Se Llama Soledad",
                                "TrackNumber": 3
                            },
                            {
                                "Artist": "",
                                "Title": "Contigo",
                                "TrackNumber": 4
                            },
                            {
                                "Artist": "",
                                "Title": "Como Un Dolor De Muelas",
                                "TrackNumber": 5
                            },
                            {
                                "Artist": "",
                                "Title": "A La Sombra De Un Leon",
                                "TrackNumber": 6
                            },
                            {
                                "Artist": "",
                                "Title": "La Cancion Mas Hermosa Del Mundo",
                                "TrackNumber": 7
                            },
                            {
                                "Artist": "",
                                "Title": "A La Sombra De Un Leon",
                                "TrackNumber": 8
                            },
                            {
                                "Artist": "",
                                "Title": "19 Dias Y 500 Noches",
                                "TrackNumber": 9
                            },
                            {
                                "Artist": "",
                                "Title": "Tan Joven Y Tan Viejo",
                                "TrackNumber": 10
                            }
                        ]
                    }
                ]
            };
        },
        AddTrackToQueue : function(AlbumID, TrackId){
            return;
        },

        SkipSong : function(){
            return;
        }



    };
    Catalog = WindowObj.GetCatalog();
    //alert(Exception);
}
var Catalog ;



//var InputBuffer = "";
//var IsAnyAlbumSelected = false;
var DebugKey = false;
var App = angular.module("JukeboxFrontEnd", []);

App.controller('AlbumController', ['$scope','$rootScope', function($scope, $rootScope){
    $scope.Albums = Catalog.Albums;
    $scope.currentPage = 0;
    $scope.pageSize = 4;
    $scope.numberOfPages=function(){
        return Math.ceil($scope.Albums.length/$scope.pageSize);
    }
    $scope.InputBuffer = "----";
    $rootScope.IsAnyAlbumSelected = false;
    $rootScope.CurrentBufferPosition = 0;
    //$rootScope.TmpBuffer = "XXXX";
    $rootScope.SelectedAlbum = {"Title": "", "ID" : 0, "Artist": ""};
    $scope.AlbumHover = 0;
}]);
App.filter('padLeft', function () {
    return function (n, len) {
        var num = parseInt(n, 10);
        len = parseInt(len, 10);
        if (isNaN(num) || isNaN(len)) {
            return n;
        }
        num = ''+num;
        while (num.length < len) {
            num = '0'+num;
        }
        return num;
    };
});
App.directive('keypressEvents', [
    '$document',
    '$rootScope',

    function( $document, $rootScope) {

        return function(scope, element, attr){
            console.log(scope.Albums);
            //element.on("keypress", function(event){
            element.on("keydown", function(event){
                var key = event.which;
                if(DebugKey){
                    console.log(event);
                }
                /*
                if( (key < 96|| key > 105 ) && key != 27 && key != 9 && key != 32 && event.keyCode != 37 && event.keyCode != 39 && event.keyCode != 27){
                    console.info("Invalid key");
                    return;
                }
                */
                Keys = [
                            96,
                            97,
                            98,
                            99,
                            100,
                            101,
                            102,
                            103,
                            104,
                            105,
                            9,
                            27,
                            39,
                            37
                        ];
                /*
                if( (key < 96|| key > 105 ) && key != 9 && key != 27 && key != 39 && key != 37){
                    console.info("Invalid key");
                    return;
                }*/
                if(Keys.indexOf(key) < 0){
                    console.info("Invalid key");
                    return;
                }

                //console.log(event);

                if(key == 27 || key == 0 && event.keyCode== 27){
                    scope.$apply(function(){
                        if(scope.InputBuffer == "----"){
                            $rootScope.IsAnyAlbumSelected = false;
                            $rootScope.CurrentBufferPosition = 0;
                            console.log("Deseleccionando album (si hay)");
                        }else{
                            scope.InputBuffer = "----";
                            $rootScope.CurrentBufferPosition = 0;
                            console.log("Limpiando buffer");
                        }
                    });
                    //$rootScope.$broadcast();
                    try{
                        scope.$apply();
                    }catch(Ex){
                        console.error(ex);
                    }

                    return;
                }
                if(key == 9 || key == 32 || (key == 0 && event.keyCode == 32)){
                    console.log("Skipping song");
                    WindowObj.SkipSong();
                    return;
                }
                if(key == 37|| (key==0 & event.keyCode == 37)){
                    if(scope.AlbumHover <= 0){
                        return;
                    }
                    scope.AlbumHover--;
                    scope.InputBuffer = parseInt(scope.AlbumHover).padLeft(4, '0');
                    scope.IsAnyAlbumSelected = false;

                    console.log(scope.AlbumHover % scope.pageSize);
                    if(scope.AlbumHover % scope.pageSize == 0){
                        if(scope.currentPage == 0){
                            scope.$apply();
                            return;
                        }
                        scope.currentPage--;
                    }
                    scope.$apply();

                    return;
                }
                if(key == 39 || (key==0 & event.keyCode == 39)){
                    if(scope.AlbumHover >= scope.Albums.length - 1){
                        return;
                    }
                    scope.AlbumHover++;
                    scope.InputBuffer = parseInt(scope.AlbumHover).padLeft(4, '0');
                    scope.IsAnyAlbumSelected = false;

                    console.log(scope.AlbumHover % scope.pageSize);
                    if(scope.AlbumHover % scope.pageSize == 0){
                        if(scope.currentPage >= scope.Albums.length/scope.pageSize -1){
                            scope.$apply();
                            return;
                        }
                        scope.currentPage++
                    }
                    scope.$apply();
                    return;
                }


                //console.log($rootScope.CurrentBufferPosition);
                //console.info(String.fromCharCode(key));
                scope.InputBuffer = scope.InputBuffer.replaceAt($rootScope.CurrentBufferPosition, String.fromCharCode(key-48));
                console.log(scope);
                $rootScope.CurrentBufferPosition++;
                if($rootScope.CurrentBufferPosition == 4){
                    var Buffer = scope.InputBuffer;
                    $rootScope.CurrentBufferPosition = 0;
                    scope.InputBuffer = "----";
                    if(!$rootScope.IsAnyAlbumSelected){
                        $rootScope.SelectedAlbum.ID = Number(Buffer);
                        $rootScope.IsAnyAlbumSelected = true;
                        scope.AlbumHover = Number(Buffer);
                        var Page = Math.ceil(scope.AlbumHover /scope.pageSize);
                        console.log( Page > 1 ? Page - 1 : 0);
                        scope.currentPage = Page > 1 ? Page - 1 : 0;//Math.ceil(scope.AlbumHover /scope.pageSize -1);
                        console.log("Album seleccionado: " + $rootScope.SelectedAlbum.ID);
                    }else{
                        console.log("Track seleccionado" + Buffer);
                        WindowObj.AddTrackToQueue($rootScope.SelectedAlbum.ID, Number(Buffer));
                    }
                }

                //console.log($rootScope.InputBuffer);
                try{
                    scope.$apply();
                }catch(Ex){
                    console.error(ex);
                }
            });
        };

    }
]);

App.filter('startFrom', function() {
    return function(input, start) {
        start = +start; //parse to int
        return input.slice(start);
    }
});
