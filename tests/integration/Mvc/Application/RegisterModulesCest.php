<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Application;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Application;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\View;

class RegisterModulesCest
{
    public function modulesDefinition(IntegrationTester $I)
    {
        $I->wantTo(
            'handle request and get content by using single modules strategy (standard definition)'
        );

        Di::reset();

        $di = new FactoryDefault();

        $di->set(
            'router',
            function () {
                $router = new Router(false);

                $router->add(
                    '/index',
                    [
                        'controller' => 'index',
                        'module'     => 'frontend',
                        'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers',
                    ]
                );

                return $router;
            }
        );

        $application = new Application();

        $application->registerModules(
            [
                'frontend' => [
                    'path'      => dataFolder('fixtures/modules/frontend/Module.php'),
                    'className' => \Phalcon\Test\Modules\Frontend\Module::class,
                ],
                'backend' => [
                    'path'      => dataFolder('fixtures/modules/backend/Module.php'),
                    'className' => \Phalcon\Test\Modules\Backend\Module::class,
                ],
            ]
        );

        $application->setDI($di);

        $response = $application->handle("/index");

        $I->assertEquals(
            '<html>here</html>' . PHP_EOL,
            $response->getContent()
        );
    }

    public function modulesClosure(IntegrationTester $I)
    {
        $I->wantTo(
            'handle request and get content by using single modules strategy (closure)'
        );

        Di::reset();

        $di = new FactoryDefault();

        $di->set(
            'router',
            function () {
                $router = new Router(false);

                $router->add(
                    '/index',
                    [
                        'controller' => 'index',
                        'module'     => 'frontend',
                        'namespace'  => 'Phalcon\Test\Modules\Frontend\Controllers',
                    ]
                );

                $router->add(
                    '/login',
                    [
                        'controller' => 'login',
                        'module'     => 'backend',
                        'namespace'  => 'Phalcon\Test\Modules\Backend\Controllers',
                    ]
                );

                return $router;
            }
        );

        $application = new Application();
        $view        = new View();

        $application->registerModules(
            [
                'frontend' => function (DiInterface $di) use ($view) {
                    $di->set(
                        'view',
                        function () use ($view) {
                            $view->setViewsDir(
                                dataFolder('fixtures/modules/frontend/views/')
                            );

                            return $view;
                        }
                    );
                },
                'backend' => function (DiInterface $di) use ($view) {
                    $di->set(
                        'view',
                        function () use ($view) {
                            $view->setViewsDir(
                                dataFolder('fixtures/modules/backend/views/')
                            );

                            return $view;
                        }
                    );
                },
            ]
        );

        $application->setDI($di);

        $response = $application->handle("/login");

        $I->assertEquals(
            '<html>here</html>' . PHP_EOL,
            $response->getContent()
        );
    }
}
