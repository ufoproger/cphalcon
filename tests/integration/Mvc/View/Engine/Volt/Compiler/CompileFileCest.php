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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt\Compiler;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

/**
 * Class CompileFileCest
 */
class CompileFileCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileFile()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-01-17
     */
    public function mvcViewEngineVoltCompilerCompileFile(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - compileFile()");

        $viewFile    = dataFolder('fixtures/views/layouts/compiler.volt');
        $compileFile = $viewFile . '.php';

        $expected = '<?php if ($some_eval) { ?>
Clearly, the song is: <?= $this->getContent() ?>.
<?php } ?>';

        $volt = new Compiler();

        $volt->compileFile($viewFile, $compileFile);

        $I->assertEquals(
            $expected,
            file_get_contents($compileFile)
        );

        $I->safeDeleteFile($compileFile);
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileFile()
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13242
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @dataProvider mvcViewEngineVoltCompilerCompileFileDefaultFilterProvider
     */
    public function mvcViewEngineVoltCompilerCompileFileDefaultFilter(IntegrationTester $I, Example $example)
    {
        $volt = new Compiler();

        $viewFile = sprintf(
            '%sfixtures/views/filters/%s.volt',
            dataFolder(),
            $example['view']
        );

        $compiledFile = $viewFile . '.php';

        $volt->compileFile($viewFile, $compiledFile);

        $I->assertEquals(
            $example['expected'],
            file_get_contents($compiledFile)
        );

        $I->safeDeleteFile($compiledFile);
    }

    private function mvcViewEngineVoltCompilerCompileFileDefaultFilterProvider(): array
    {
        return [
            [
                'view'     => 'default',
                'expected' => "<?= (empty(\$robot->price) ? (10.0) : (\$robot->price)) ?>\n",
            ],

            [
                'view'     => 'default_json_encode',
                'expected' => "<?= json_encode((empty(\$preparedParams) ? ([]) : (\$preparedParams))) ?>\n",
            ],
        ];
    }
}
